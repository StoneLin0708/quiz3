#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

uint64_t gcd64(uint64_t u, uint64_t v)
{
    if (!u || !v)
        return u | v;

    int uz = __builtin_ctz(u);
    int vz = __builtin_ctz(v);

    int shift = uz > vz ? vz : uz;
    u >>= shift;
    v >>= shift;
    while (!(u & 1))
        u /= 2;
    do {
        while (!(v & 1))
            v /= 2;
        if (u < v) {
            v -= u;
        } else {
            uint64_t t = u - v;
            u = v;
            v = t;
        }
    } while (v);
    return u << shift;
}

void ex(int a, int b)
{
    printf("gcd(%d,%d)=%ld\n", a, b, gcd64(a, b));
}
int main(int argc, char const *argv[])
{
    ex(15, 5);
    ex(15, 7);
    ex(3, 21);
    return 0;
}
