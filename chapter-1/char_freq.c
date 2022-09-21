#include <stdio.h>

#define ALPHABET_SIZE 26 // to support different alphabets at some point
#define HISTOGRAM_BAR_LENGTH 100 // characters

int main()
{
    int i, c, max, j;
    int freq[ALPHABET_SIZE];
    for (i = 0; i < ALPHABET_SIZE; ++i)
        freq[i] = 0;
    
    while ((c = getchar()) != EOF) {
        if (c >= 'A' && c <= 'Z')
            freq[c - 'A'] += 1;
        else if (c >= 'a' && c <= 'z')
            freq[c - 'a'] += 1;
    }

    max = 0;
    for (i = 0; i < ALPHABET_SIZE; ++i) {
        if (max < freq[i]) {
            max = freq[i];
        }
    }

    printf("CHARACTER COUNT:\n");
    for (i = 0; i < ALPHABET_SIZE; ++i) {
        printf("%c: %5d ", (i + 'A'), freq[i]);
        for (j = 0; j < (int)(HISTOGRAM_BAR_LENGTH * freq[i] / (float)max); ++j)
            printf("|");
        printf("\n");
    }
}