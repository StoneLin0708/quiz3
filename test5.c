#include <ctype.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

size_t improved(uint64_t *bitmap, size_t bitmapsize, uint32_t *out)
{
    size_t pos = 0;
    uint64_t bitset;
    for (size_t k = 0; k < bitmapsize; ++k) {
        bitset = bitmap[k];
        while (bitset != 0) {
            uint64_t t = bitset & -bitset;
            int r = __builtin_ctzll(bitset);
            out[pos++] = k * 64 + r;
            bitset ^= t;
        }
    }
    return pos;
}

int main(int argc, char const *argv[])
{
    uint64_t bitmap[10] = {0xF3, 1, 0};
    uint32_t out[64];
    size_t s = improved(&bitmap, 2, &out);
    for (int i = 0; i < s; ++i) {
        printf("%x\n", out[i]);
    }
}
