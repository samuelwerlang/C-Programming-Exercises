#include <stdio.h>
#include <inttypes.h>

uint8_t setbits(uint8_t x, int p, int n, uint8_t y);

int main(void)
{
    uint8_t x = 7;
    uint8_t y = 8;
    printf("%hhu\n", setbits(x, 3, 2, y));
    return 0;
}

uint8_t setbits(uint8_t x, int p, int n, uint8_t y)
{
    uint8_t mask = ((1U << n) - 1) << (p-n+1);
    x &= ~mask;
    uint8_t ybits = (y & (1U << n) - 1);
    ybits <<= p-n+1;
    return x | ybits;
}
