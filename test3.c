#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int numberOfSteps(int num)
{
    return num ? __builtin_popcount(num) + 31 - __builtin_clz(num) : 0;
}

int main(int argc, char const *argv[])
{
    printf("%x, %d\n", 0x4, numberOfSteps(0x3));
}
