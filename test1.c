#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int asr_i(signed int m, unsigned int n)
{
    const int logical = (((int) -1) >> 1) > 0;
    unsigned int fixu = -(logical & (m < 0));
    int fix = *(int *) &fixu;
    return (m >> n) | (fix ^ (fix >> n));
}

void exam(int x, int s)
{
    int r = asr_i(x, s);
    printf("%d[%x] >> %d => %d[%x]\n", x, x, s, r, r);
}

int main(int argc, char const *argv[])
{
    exam(-1, 2);
    exam(-1, 1);
    exam(0x80000000, 2);
    return 0;
}
