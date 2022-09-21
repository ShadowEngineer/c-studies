#include <stdio.h>

#define MAX_WORD_LENGTH 20
#define IN 1
#define OUT 0

int main()
{
    int i, c, state, cwl, j;
    int wls[MAX_WORD_LENGTH + 1];
    for (i = 0; i <= MAX_WORD_LENGTH; ++i)
        wls[i] = 0;

    state = OUT;
    cwl = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            wls[cwl] += 1;
            cwl = 0;
        } else {
            ++cwl;
        }
    }

    for (i = 0; i <= MAX_WORD_LENGTH; ++i) {
        printf("%2d - %3d: ", i, wls[i]);
        for (j = 0; j < wls[i]; ++j)
            printf("#");
        printf("\n");
    }
    printf("\n");
}