#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool hasReplaced = false;
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (hasReplaced == false) {
                hasReplaced = true;
                putchar(c);
            }
        } else {
            hasReplaced = false;
            putchar(c);
        }
    }
}