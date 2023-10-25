#include <stdio.h>

#define MAXLEN 200

void escape(char string[], char target[]);
void escape_reverse(char string[], char target[]);

int main()
{
    char s[MAXLEN], t[MAXLEN], u[MAXLEN], c;
    int i = 0;

    printf("Enter the string: ");
    while ((c = getchar()) != EOF)
        s[i++] = c;
    s[i] = '\0';
    escape(s, t);
    printf("\nThe escaped string: %s\n", t);
    escape_reverse(t, u);
    printf("The re-escaped string is: %s\n", u);
    return 0;
}

/* escape: copies the characters from string to target, replacing newlines and tabs with their visible escape sequences */
void escape(char string[], char target[])
{
    int i = 0, j = 0;

    while (string[i] != '\0')
    {
        switch (string[i])
        {
        case '\n':
            target[j++] = '\\';
            target[j++] = 'n';
            i++;
            break;
        case '\t':
            target[j++] = '\\';
            target[j++] = 't';
            i++;
            break;
        default:
            target[j++] = string[i++];
            break;
        }
    }
    target[j] = '\0';
}

void escape_reverse(char string[], char target[])
{
    int i = 0, j = 0;

    while (string[i] != '\0')
        if (string[i] == '\\')
            switch (string[i + 1])
            {
            case 't':
                target[j++] = '\t';
                i += 2;
                break;
            case 'n':
                target[j++] = '\n';
                i += 2;
                break;
            }
        else
            target[j++] = string[i++];
    target[j] = '\0';
}