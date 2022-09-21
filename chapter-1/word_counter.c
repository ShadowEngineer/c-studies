#include <stdio.h>

#define IN 1        // in a word
#define OUT 2       // out of a word

int main()
{
    int c, nl, nw, nc, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n')
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            putchar('\n'); // every word gets a new line
            state = IN;
            ++nw;
        }

        putchar(c);
    }
    printf("%d lines, %d words, %d characters\n", nl, nw, nc);
}