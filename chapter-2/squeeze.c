#include <stdio.h>

void squeeze(char s[], int c);
void squeeze2(char s1[], char s2[]);
int any(char *s1, char *s2);

int main()
{
    /* squeeze testing */
    char s1[] = "Hello world.";
    squeeze(s1, 'l');
    printf("%s\n", s1);

    /* squeeze2 testing */
    char s2[] = "Lorem Ipsum dolor sit amet. Hello world. Testing testing 1 2 3.";
    squeeze2(s2, "Hello");
    printf("%s\n", s2);

    /* any testing */
    printf("Position of \"abcde\" in string [%s]: %d\n", s2, any(s2, "abcde"));
    printf("Position of \"fghij\" in string [%s]: %d\n", s2, any(s2, "fghij"));
    printf("Position of \"yx\" in string [%s]: %d\n", s2, any(s2, "yx"));

    return 0;
}

/* squeeze: delete all occurrences of character c from string s */
void squeeze(char s[], int c)
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

/* squeeze2: delete all characters in string s1 that appear in string s2 */
void squeeze2(char s1[], char s2[])
{
    int i;
    for (i = 0; s2[i] != '\0'; i++)
        squeeze(s1, s2[i]);
}

/* any: returns the first location in the string s1 where any character from the string s2 occurs, or -1 otherwise. */
int any(char *s1, char *s2)
{
    int i, j;
    for (i = j = 0; *(s1 + i) != '\0'; i++)
        for (j = 0; *(s2 + j) != '\0'; j++)
            if (*(s1 + i) == *(s2 + j))
                return i;
    return -1;
}