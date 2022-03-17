#include <stdio.h>
#include <stdlib.h>

#include "bits1.h"

const unsigned int BitsInUint = sizeof(unsigned int) * 8;

unsigned int reverseBits1(unsigned int num) {
    unsigned int x, bit, i, j;

    x = 0;
    for (i = BitsInUint - 1, j = 0; j < BitsInUint; i--, j++) {
        bit = 1 << i;
        if ((num & bit) == bit) {
            x |= 1 << j;
        }
    }
    return x;
}
