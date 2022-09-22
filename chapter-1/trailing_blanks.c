#include <stdio.h>
#include <stdbool.h>

bool is_blank(char c);

int main()
{
    int c, i, whitespace_count;
    bool currently_blank;
    
    currently_blank = false;
    while ((c = getchar()) != EOF) {
        if (is_blank(c) == true) {
            currently_blank = true;
            whitespace_count = 0;

            do {
                if (is_blank(c) == true) {
                    ++whitespace_count;
                } else if (c == '\n') {
                    currently_blank = false;
                    putchar(c);
                } else {
                    for (i = 0; i < whitespace_count; ++i) {
                        putchar(' ');
                    }
                    currently_blank = false;
                    putchar(c);
                }

                if (currently_blank == true) {
                    c = getchar();
                }
            }
            while (c != EOF && currently_blank == true);

            if (c == EOF) {
                return 0;
            }
        } else {
            putchar(c);
        }
    }
}

bool is_blank(char c)
{
    return c == '\t' || c == ' ';
}