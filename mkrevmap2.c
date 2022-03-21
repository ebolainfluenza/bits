#include <stdio.h>
#include <stdlib.h>

#include "bits1.h"

extern const unsigned int BitsInUint;

int main(int argc, char **argv) {
    unsigned int i, x;

    fprintf(stdout, "const unsigned int revmap2[] = {");
    for (i = 0; i < 256; i++) {
        if (i % 16 == 0)    /* output 16 columns */
            fprintf(stdout, "\n\t");
        x = reverseBits1(i);
        x = (x & 0xff << (BitsInUint - 8)) >> (BitsInUint - 8);
        fprintf(stdout, "0x%02x, ", x);
    }
    fprintf(stdout, "\n};\n");
    exit(EXIT_SUCCESS);
}
