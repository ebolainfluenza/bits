#include <stdio.h>
#include <stdlib.h>

typedef struct Test Test;

struct Test {
    unsigned int input;
    unsigned int expected;
};

const unsigned int bitsInUint = sizeof(unsigned int) * 8;

// revmap is an array of nibbles that are the reverse of their index
const unsigned int revmap[] = {
    0x0, 0x8, 0x4, 0xc, 
    0x2, 0xa, 0x6, 0xe, 
    0x1, 0x9, 0x5, 0xd, 
    0x3, 0xb, 0x7, 0xf,
};

// multfour is an array of multiples of four
const unsigned int multfour[] = {
    0, 4, 8, 12, 16, 20, 24, 28, 
    32, 36, 40, 44, 48, 52, 56, 60, 64,
};

#define NELEM(x) if(x) {sizeof(x)/sizeof((x)[0])} else {0}

unsigned int reverseBits1(unsigned int num) {
    unsigned int x, bit, i, j;

    x = 0;
    for (i = bitsInUint - 1, j = 0; j < bitsInUint; i--, j++) {
        bit = 1 << i;
        if ((num & bit) == bit) {
            x |= 1 << j;
        }
    }
    return x;
}

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

int main(int argc, char **argv) {
    unsigned int got;
    Test **t, *tests[] = {
		&(Test){0, 0},
		&(Test){1, 1 << (bitsInUint - 1)},
		&(Test){0xf, 0xf << (bitsInUint - 4)},
		&(Test){0xf0f, 0xf0f << (bitsInUint - 12)},
		&(Test){0xa, 0x5 << (bitsInUint - 4)},
		&(Test){0xabcdef, 0xf7b3d5 << (bitsInUint - 24)},
		&(Test){0xcafebabe, 0x7d5d7f53 << (bitsInUint - 32)},
        NULL,
    };

    for (t = tests; *t; t++) {
        got = reverseBits1((*t)->input);
        if (got != (*t)->expected) {
            fprintf(stderr, "reversebits1:\n\tinput:    0x%x\n\texpected: 0x%x\n\tgot:      0x%x\n", 
                (*t)->input, (*t)->expected, got);
            exit(EXIT_FAILURE);
        }
    }
    for (t = tests; *t; t++) {
        got = reverseBits2((*t)->input);
        if (got != (*t)->expected) {
            fprintf(stderr, "reversebits2:\n\tinput:    0x%x\n\texpected: 0x%x\n\tgot:      0x%x\n", 
                (*t)->input, (*t)->expected, got);
            exit(EXIT_FAILURE);
        }
    }
    exit(EXIT_SUCCESS);
}
