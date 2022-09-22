#include <stdio.h>
#define MAXLINE 1000 // maximum input line size

int get_line(char line[], int maxLine);
void copy(char to[], char from[]);

/* print longest line */
int main()
{
    int len;            /* current line length*/
    int max;            /* maximum line length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) {      /* there was a line */
        printf("LONGEST LENGTH %d: %s", max, longest);
    }
    return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim)
{
    int c, i, last;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
        ++last;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
        last = i;
    } else {
        if (c != EOF) {
            for (i = i; (c = getchar()) != EOF && c != '\n'; ++i)
                ;
        }
    }
    s[last] = '\0';

    return i;
}

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}