#include <stdio.h>
#include <stdlib.h>

const unsigned int bitsInUint = sizeof(unsigned int) * 8;

typedef struct Test Test;

struct Test {
    unsigned int input;
    unsigned int expected;
};

unsigned int reverseBits(unsigned int num) {
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
        got = reverseBits((*t)->input);
        if (got != (*t)->expected) {
            fprintf(stderr, "\ninput:    0x%x\nexpected: 0x%x\ngot:      0x%x\n", 
                (*t)->input, (*t)->expected, got);
            exit(EXIT_FAILURE);
        }
    }
    exit(EXIT_SUCCESS);
}
