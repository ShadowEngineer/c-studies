#include <stdio.h>

int main()
{
    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF)
        if (c == '\n') // usage of "" here is not ideal, since the compiler will warn against comparing pointers (the string in this case) to integers
            ++nl;
    printf("\n%d\n", nl);
}