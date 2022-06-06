// Physical memory allocator, intended to allocate
// memory for user processes, kernel stacks, page table pages,
// and pipe buffers. Allocates 4096-byte pages.

#include "types.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "spinlock.h"

void freerange(void *vstart, void *vend);
extern char end[]; // first address after kernel loaded from ELF file
				   // defined by the kernel linker script in kernel.ld
#ifdef COW
struct
{
	struct spinlock lock;
	int use_lock;
	int numfreepages;
	uint ref[PHYSTOP >> PGSHIFT];
} pmem;
#endif

struct run
{
	struct run *next;
};

struct
{
	struct spinlock lock;
	int use_lock;
	struct run *freelist;
} kmem;

// Initialization happens in two phases.
// 1. main() calls kinit1() while still using entrypgdir to place just
// the pages mapped by entrypgdir on free list.
// 2. main() calls kinit2() with the rest of the physical pages
// after installing a full page table that maps them on all cores.
void kinit1(void *vstart, void *vend)
{
#ifdef COW
	initlock(&pmem.lock, "pmemlock");
	pmem.use_lock = 0;
#endif
	initlock(&kmem.lock, "kmem");
	kmem.use_lock = 0;
	freerange(vstart, vend);
}

void kinit2(void *vstart, void *vend)
{
#ifdef COW
	pmem.use_lock = 1;
	memset(&pmem.ref, 0, sizeof(uint) * (PHYSTOP >> PGSHIFT));
	acquire(&pmem.lock);
	pmem.numfreepages = 0;
	release(&pmem.lock);
#endif
	freerange(vstart, vend);
	kmem.use_lock = 1;
}

void freerange(void *vstart, void *vend)
{
	char *p;
	p = (char *)PGROUNDUP((uint)vstart);
	for (; p + PGSIZE <= (char *)vend; p += PGSIZE)
		kfree(p);
}
#ifdef COW
// reference counter APIs
int freemem()
{
	int numfreepages;
	acquire(&pmem.lock);
	numfreepages = pmem.numfreepages;
	release(&pmem.lock);
	return numfreepages;
}

void pa_check(uint pa)
{ // pa range check
	if (pa >= PHYSTOP)
		panic("invalid physical address range");
	if (pmem.use_lock)
		acquire(&pmem.lock);
}

uint get_ref(uint pa)
{
	pa_check(pa);
	if (pmem.use_lock)
		release(&pmem.lock);
	return pmem.ref[pa >> PGSHIFT]; // physical memory pages
}

void inc_ref(uint pa)
{
	pa_check(pa);
	pmem.ref[pa >> PGSHIFT]++; // increase the reference count of pa

	if (pmem.use_lock)
		release(&pmem.lock);
	return;
}

void dec_ref(uint pa)
{
	pa_check(pa);
	pmem.ref[pa >> PGSHIFT]--; // decrease the reference count of pa

	if (pmem.use_lock)
		release(&pmem.lock);
	return;
}

#endif
// PAGEBREAK: 21
//  Free the page of physical memory pointed at by v,
//  which normally should have been returned by a
//  call to kalloc().  (The exception is when
//  initializing the allocator; see kinit above.)
void kfree(char *v)
{
	struct run *r;

	if ((uint)v % PGSIZE || v < end || V2P(v) >= PHYSTOP)
		panic("kfree");

	// Fill with junk to catch dangling refs.
	r = (struct run *)v;

#ifdef COW

	uint pa = V2P(v);
	if (pmem.ref[pa >> PGSHIFT] > 0) // counter--
		dec_ref(pa);

	if (pmem.ref[pa >> PGSHIFT] == 0) // free memory
	{
		memset(v, 1, PGSIZE);
		r->next = kmem.freelist; // add freelist
		kmem.freelist = r;
		pmem.numfreepages++; // increase freelist
	}
#endif
}

// Allocate one 4096-byte page of physical memory.
// Returns a pointer that the kernel can use.
// Returns 0 if the memory cannot be allocated.
char *
kalloc(void)
{
	struct run *r;

	if (kmem.use_lock)
		acquire(&kmem.lock);
	r = kmem.freelist;
	if (r) // check freelist
	{
		kmem.freelist = r->next;

#ifdef COW
		if (pmem.use_lock)
			acquire(&pmem.lock);

		pmem.numfreepages--;

		uint pa = V2P((uint)r);
		pmem.ref[pa >> PGSHIFT]++;

		if (pmem.use_lock)
			release(&pmem.lock);
#endif
	}
	if (kmem.use_lock)
		release(&kmem.lock);

	return (char *)r;
}
