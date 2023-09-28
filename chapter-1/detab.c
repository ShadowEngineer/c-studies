#include <stdio.h>

#define TAB_COLUMN_WIDTH 8 // the maximum number of blanks equivalent to a tab

int main(int argc, char **argv)
{
    int c;
    while ((c = getchar()) != EOF)
        putchar(c);
    putchar('\n');
}