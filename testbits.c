#include <stdio.h>
#include <stdlib.h>

#include "bits1.h"
#include "bits2.h"

typedef struct Test Test;

struct Test {
    unsigned int input;
    unsigned int expected;
};

extern const unsigned int BitsInUint;

void test(Test **tests, unsigned int (fxn)(unsigned int), char *name) {
    unsigned int got;
    Test **t;

    for (t = tests; *t; t++) {
        got = (fxn)((*t)->input);
        if (got != (*t)->expected) {
            fprintf(stderr, "%s:\n\tinput:    0x%x\n\texpected: 0x%x\n\tgot:      0x%x\n", 
                name, (*t)->input, (*t)->expected, got);
            exit(EXIT_FAILURE);
        }
    }
}

int main(int argc, char **argv) {
    Test *tests[] = {
		&(Test){0, 0},
		&(Test){1, 1 << (BitsInUint - 1)},
		&(Test){0xf, 0xf << (BitsInUint - 4)},
		&(Test){0xf0f, 0xf0f << (BitsInUint - 12)},
		&(Test){0xa, 0x5 << (BitsInUint - 4)},
		&(Test){0xabcdef, 0xf7b3d5 << (BitsInUint - 24)},
		&(Test){0xcafebabe, 0x7d5d7f53 << (BitsInUint - 32)},
        NULL,
    };

    test(tests, reverseBits1, "reversebits1");
    test(tests, reverseBits2, "reversebits2");
    test(tests, reverseBits3, "reversebits3");
    fprintf(stdout, "success\n");
    exit(EXIT_SUCCESS);
}
