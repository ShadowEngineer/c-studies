#include <stdio.h>
#define MINIMUM_LINE_LENGTH 80

int main()
{
    int c, i, j;
    char long_line[MINIMUM_LINE_LENGTH];

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            i = 0;
        } else {
            ++i;
            long_line[i] = c;
        }

        if (i == MINIMUM_LINE_LENGTH - 1) {
            printf("\nLONGER THAN %d: %s", MINIMUM_LINE_LENGTH, long_line);
            while ((c = getchar()) != '\n') {
                putchar(c);
            }
        }
    }
}