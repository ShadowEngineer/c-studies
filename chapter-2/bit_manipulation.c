#include <stdio.h>
#include <math.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);

long to_binary(long n);

int main()
{
    unsigned x = 420; //((int)pow(2, 5)) - 1;
    unsigned y = 69;
    int p = 6;
    int n = 4;
    printf("Arguments:\n\tx = %032ld\t(%d)\n\ty = %032ld\t(%d)\n\tp = %d\n\tn = %d\n", to_binary(x), x, to_binary(y), y, p, n);

    printf("setbits(%032ld, %d, %d, %032ld) = \n\t%032ld\n", to_binary(x), p, n, to_binary(y), to_binary(setbits(x, p, n, y)));
    printf("invert( %032ld, %d, %d) = \n\t%032ld\n", to_binary(x), p, n, to_binary(invert(x, p, n)));
    printf("rightrot(%032ld, %d) = \n\t %032ld\n", to_binary(x), n, to_binary(rightrot(x, n)));
    return 0;
}

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    // int shift_left_amount = p + 1 - n;
    // unsigned right_most_shift = ~(~0 << n);
    // unsigned right_most_from_y = y & right_most_shift;
    // unsigned y_right_shifted = right_most_from_y << shift_left_amount;
    // unsigned mask_for_x = ~(right_most_shift << shift_left_amount);
    // unsigned result = (x & mask_for_x) | y_right_shifted;

    if (n == 0)
        return x;
    // yeah good luck trying to comprehend this demon of a one-liner...
    return (x & ~(~(~0u << n) << (p + 1 - n))) | (y & ~(~0u << n)) << (p + 1 - n);
}

unsigned invert(unsigned x, int p, int n)
{
    if (n == 0)
        return x;
    return setbits(x, p, n, ~0 ^ getbits(x, p, n));
}

// this does actually work, it just returns a number so high that to_binary can't print it properly
unsigned rightrot(unsigned x, int n)
{
    if (n == 0)
        return x;
    return setbits(x >> n, sizeof(x) * 8 - 1, n, getbits(x, n - 1, n));
}

long to_binary(long n)
{
    if (n == 0)
        return 0;
    else
        return (n % 2) + 10 * to_binary(n / 2);
}