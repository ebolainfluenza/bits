#include <stdio.h>
#include <stdlib.h>

#include "bits2.h"
#include "revmap2.h"

// revmap is an array of nibbles that are the reverse of their index
static const unsigned int revmap[] = {
    0x0, 0x8, 0x4, 0xc, 
    0x2, 0xa, 0x6, 0xe, 
    0x1, 0x9, 0x5, 0xd, 
    0x3, 0xb, 0x7, 0xf,
};

// multfour is an array of multiples of four
static const unsigned int multfour[] = {
    0, 4, 8, 12, 16, 20, 24, 28, 
    32, 36, 40, 44, 48, 52, 56, 60, 64,
};

// multeight is an array of multiples of eight
static const unsigned int multeight[] = {
    0, 8, 16, 24, 32, 40, 48, 56, 64,
};

unsigned int reverseBits2(unsigned int num) {
    unsigned int x, i, nibbles, rev;

    x = 0;
    nibbles = sizeof(unsigned int) << 1;
    for (i = 0; i < nibbles; i++) {
        rev = revmap[(num & 0xf << multfour[i]) >> multfour[i]];
        x |= rev << multfour[nibbles - 1 - i];
    }
    return x;
}

unsigned int reverseBits3(unsigned int num) {
    unsigned int x, i, nbytes, rev;

    x = 0;
    nbytes = sizeof(unsigned int);
    for (i = 0; i < nbytes; i++) {
        rev = revmap2[(num & 0xff << multeight[i]) >> multeight[i]];
        x |= rev << multeight[nbytes - 1 - i];
    }
    return x;
}
