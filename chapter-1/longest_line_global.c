#include <stdio.h>

#define MAX_LINE 1000

int max;
char line[MAX_LINE];
char longest[MAX_LINE];

int get_line(void);
void copy(void);


// print the longest input line; specialised version
int main()
{
    int len;

    max = 0;
    while ((len = get_line()) > 0)
        if (len > max) {
            max = len;
            copy();
        }

    if (max > 0)    // there was a line
        printf("%s", longest);

    return 0;
}

// get_line: specialised version
int get_line(void)
{
    int c, i;

    for (i = 0; i < MAX_LINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';
    return i;
}

// copy: specialised version
void copy(void)
{
    int i;

    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}