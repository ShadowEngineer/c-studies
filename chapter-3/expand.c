#include <stdio.h>

void expand(char s1[], char s2[]);

int main()
{
    char s1[] = "f-lA-Z1-5";
    char s2[100];
    expand(s1, s2);
    printf("%s -> %s\n", s1, s2);
    return 0;
}

/*
Expands statements in s1 like a-z into s2 as abcdefghijklmnopqrstuvwxyz.
Assumes s2 has enough space.

Does not allow expressions like a-b-c and -a-z (whatever that even means)
half complete
*/
void expand(char s1[], char s2[])
{
    int i, j, last_j;
    char c, start, end;

    last_j = 0;
    for (i = 0; (c = s1[i]) != '\0'; ++i)
    {
        start = c;
        c = s1[++i];
        if (c != '-')
            return;
        c = s1[++i];
        end = c;

        /* filling s2 */
        for (j = 0; j <= end - start; ++j)
            s2[last_j + j] = start + j;
        last_j += end - start;
    }
    s2[last_j + 1] = '\0';
}