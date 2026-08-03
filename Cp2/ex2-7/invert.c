#include <stdio.h>

unsigned invert(unsigned x, int p, int n) 
{
    if (p-n+1 < 0)
        goto error;
    unsigned mask = ((1U << n) - 1) << (p-n+1);
    x ^= mask; 
    return x;

error:
    return (unsigned) -1;
}

int main(void)
{
    unsigned x = 5;
    printf("%u\n", invert(x, 3, 3));
    return 0;
}
