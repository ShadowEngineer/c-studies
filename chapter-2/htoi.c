#include <stdio.h>

int htoi(char s[]);

int main()
{
    printf("%d\n", htoi("FF"));     // 255
    printf("%d\n", htoi("9a"));     // 154
    printf("%d\n", htoi("1234F"));  // 74575
    printf("%d\n", htoi("FFFFFF")); // 16777215
    // printf("%d\n", htoi("0xFF"));
    // printf("%d\n", htoi("0XFF"));
}

int htoi(char s[])
{
    int i, n;

    n = 0;
    for (i = 0; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'f') || (s[i] >= 'A' && s[i] <= 'F'); ++i) {
        n *= 16;
        if (s[i] >= '0' && s[i] <= '9') {
            n += s[i] - '0';
        } else if (s[i] >= 'a' && s[i] <= 'f') {
            n += s[i] + 10 - 'a';
        } else {
            n += s[i] + 10 - 'A';
        }
    }

    return n;
}