#include <stdio.h>

int lower(int c);
int is_digit(int c);

int main()
{
    /* testing lower */
    printf("%c\n", lower('B')); // should return 'b'
    printf("%c\n", lower('g')); // should return 'g'

    /* testing digit check */
    printf("%d\n", is_digit('a')); // false
    printf("%d\n", is_digit('2')); // true

    return 0;
}

/* lower: convert c to lower case; ASCII only */
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 'a';
    else
        return c;
}

int is_digit(int c)
{
    return c >= '0' && c <= '9';
}