/**
 * File   : blank_counter.c
 * License: GNU v3.0
 * Author : Mark Elbre <mje248@student.bham.ac.uk>
 * Date   : 18.07.2023
 */
#include <stdio.h>

int main()
{
    int c, b, t, nl;
    c = b = t = nl = 0;

    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
        case ' ':
            ++b;
            break;
        case '\t':
            ++t;
            break;
        case '\n':
            ++nl;
            break;
        }
    }

    printf("Blanks:\t\t%d\nTabs:\t\t%d\nNew lines:\t%d\n", b, t, nl);
}
