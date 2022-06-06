#include "types.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "spinlock.h"
#include "slab.h"
#include "stdbool.h" // bool

#define PAGESIZE 4096
#define MINSLAB 8
#define MAXSLAB 2048
#define MAXBITMAP 32768 

struct {
	struct spinlock lock;
	struct slab slab[NSLAB];
} stable;

bool get_bit(char *num, int i){
	int index = (i / MINSLAB), offset = (i % MINSLAB);
	num += index;

	return ((*num & (1 << offset)) != 0);
}

void set_bit(char *num, int i){
	int index = (i / MINSLAB), offset = (i % MINSLAB);
	num += index;
	
	*num = *num | (1 << offset);
	if((i == MINSLAB) && (*num > MAXBITMAP))
		*num >>= 1;
}

char* clear_bit(char *num, int i){
	int index = (i / MINSLAB), offset = (i % MINSLAB);
	num += index;

	*num = *num & ~(1 << offset);
	return num;
}

void slabinit(){

	initlock(&stable.lock, "stable");
	acquire(&stable.lock);

	for(int i = 0; i < NSLAB; i ++){

		stable.slab[i].size = MINSLAB << i; // slab size { 8 16 32 64 128 256 512 1024 2048 }
		stable.slab[i].num_pages = 0;
		stable.slab[i].num_objects_per_page = PAGESIZE / stable.slab[i].size;
		stable.slab[i].num_free_objects = stable.slab[i].num_objects_per_page;
		stable.slab[i].num_used_objects = 0;
		stable.slab[i].bitmap = kalloc();
		memset(stable.slab[i].bitmap, 0, PAGESIZE);
		stable.slab[i].page[stable.slab[i].num_pages++] = kalloc();
	}
	release(&stable.lock);
}

char *kmalloc(int size){
	
	struct slab *s = 0;
	char *addr = 0;
	
	if(size > 0 && size <= MAXSLAB) {

		acquire(&stable.lock);

		for(s = stable.slab; s < &stable.slab[NSLAB]; s++){

			if(size <= s->size) break; // find size
		}
			
		if(s->num_free_objects == 0){ // not enough free space
			if(s->num_pages >= MAX_PAGES_PER_SLAB){
				release(&stable.lock);
				return 0;
			}

			s->page[s->num_pages] = kalloc();

			if(s->page[s->num_pages] == 0){ // avaliable page
				release(&stable.lock);
				return 0;
			}
			s->num_pages++;
			s->num_free_objects += s->num_objects_per_page; // new page
		}
		int len = s->num_pages * s->num_objects_per_page;

		for(int i=0; i<len; i++){ // allocate

			if(!get_bit(s->bitmap, i)){
				int page_index = i / s->num_objects_per_page;
				int page_offset = i % s->num_objects_per_page;

				addr = s->page[page_index] + (page_offset * s->size);

				set_bit(s->bitmap, i);

				s->num_free_objects -= 1; // modified free or used
				s->num_used_objects += 1;

				break;
			}
		}
		release(&stable.lock);
	}
	return addr;
}

void kmfree(char *addr, int size){

	struct slab *s;
	acquire(&stable.lock);
	if(size > 0 && size <= MAXSLAB) {

		for(s = stable.slab; s < &stable.slab[NSLAB]; s++){

			int count = 0;
			for(int i = 0; i < (s -> num_pages); i++){

				for(int j = 0; j < (s -> num_objects_per_page); j++){

					if(addr == s -> page[i] + (j * s -> size)){
						s -> num_free_objects++;
						s -> num_used_objects--;
						clear_bit((s -> bitmap), i *  s -> num_objects_per_page + j);
						if((s -> num_used_objects) < ((s -> num_pages - 1) + count) * s -> num_objects_per_page){
							s -> num_free_objects -= s -> num_objects_per_page;
							kfree(s -> page[s -> num_pages - 1 + count]);
							count--;
						}
						release(&stable.lock);
						s -> num_pages += count;
						return;
					}
				}s -> num_pages += count;
			}
		}
	}
	release(&stable.lock);
}

void slabdump(){
	cprintf("__slabdump__\n");

	struct slab *s;

	cprintf("size\tnum_pages\tused_objects\tfree_objects\n");

	for(s = stable.slab; s < &stable.slab[NSLAB]; s++){
		cprintf("%d\t%d\t\t%d\t\t%d\n", 
			s->size, s->num_pages, s->num_used_objects, s->num_free_objects);
	}
}
int numobj_slab(int slabid)
{
	return stable.slab[slabid].num_used_objects;
}