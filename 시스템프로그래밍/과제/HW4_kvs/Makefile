SRCS = static_main.c
SRCS2 = dynamic_main.c
LIBSRCS = open.c close.c put.c get.c 
TARG = kvs_static
TARG2 = kvs_dynamic

CC = gcc
OPTS = -Wall -O
OPTS2 = -Wall -DRUNTIME -shared -fpic -o
LIBS = -L. -lkvs
LIBS2 = -ldl

OBJS = $(SRCS:.c=.o)
OBJS2 = $(SRCS2:.c=.o)
LOBJS = $(LIBSRCS:.c=.o)
LARS = libkvs.a
LARS2 = libkvs.so

all: 

static: $(TARG)

$(TARG) : $(OBJS) $(LARS)
	$(CC) -o $(TARG) $(OBJS) $(LIBS) 

$(LARS) : $(LOBJS)
	ar rs $(LARS) $(LOBJS)

dynamic: $(TARG2)

$(TARG2) : $(LARS2)
	$(CC) -o $(TARG2) $(SRCS2) $(LIBS2) 

$(LARS2) : 
	$(CC) -o $(OPTS2) $(LARS2) $(LIBSRCS) 

%.o: %.c
	$(CC) $(OPTS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS2) $(LOBJS) $(LARS) $(LARS2) $(TARG) $(TARG2)