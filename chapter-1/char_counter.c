#include <stdio.h>

/* count characters in input */
int main()
{
    /* 1st version
    long nc;

    nc = 0;
    while (getchar() != EOF)
        ++nc;
    printf("\n%1li\n", nc);
    */

    double nc;

    for (nc = 0.0; getchar() != EOF; ++nc)
        ; // null statement since for loops must have a body
    printf("\n%.0f\n", nc);
}