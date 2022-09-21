#include <stdio.h>

/*
read a character
while (character is not end-of-file indicator)
    output the character just read
    read another character
*/

int main()
{
    /* original program
    int c;

    while ((c = getchar()) != EOF)
        putchar(c);
    */

    // verifying that `getchar() != EOF` is either a 0 or a 1
    printf("%d", getchar() != EOF);

    // printing the value of EOF - which is -1, interestingly enough
    printf("%d", EOF);
}