#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

bool isPowerOfFour(int num)
{
    return num > 0 && (num & (num - 1)) == 0 && !(__builtin_ctz(num) & 0x1);
}


int main(int argc, char const *argv[])
{
    for (int i = 0; i < 17; ++i)
        printf("%d, %d\n", i, (int) isPowerOfFour(i));
    return 0;
}
