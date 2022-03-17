AR=ar
ARCH=o
CC=gcc
CFLAGS=-Wall -O0 -g
TARGS=libbits.a mkrevmap2 testbits

all: $(TARGS)

revbits1.$(ARCH): revbits1.c
	$(CC) $(CFLAGS) -c revbits1.c

mkrevmap2: revbits1.$(ARCH) mkrevmap2.c
	$(CC) $(CFLAGS) -o mkrevmap2 mkrevmap2.c revbits1.$(ARCH)

revbits2.$(ARCH): mkrevmap2 revbits2.c
	./mkrevmap2 > revmap2.h
	$(CC) $(CFLAGS) -c revbits2.c

libbits.a: revbits1.$(ARCH) revbits2.$(ARCH)
	$(AR) -crs libbits.a revbits1.$(ARCH) revbits2.$(ARCH)

testbits: mkrevmap2 libbits.a testbits.c
	$(CC) $(CFLAGS) -o testbits testbits.c libbits.a

nuke: clean
	rm -f revmap2.h

clean:
	rm -f *.out *.$(ARCH) $(TARGS)
