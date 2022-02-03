CC=gcc
CFLAGS=-Wall -O0 -g
TARG=bitrev

all:
	$(CC) $(CFLAGS) -o $(TARG) bits.c

clean:
	rm -f *.out *.$(ARCH) $(TARG)
