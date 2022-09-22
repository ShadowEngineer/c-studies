#include <stdio.h>

#define MAX_LINE_LENGTH 100

/* reverses the order of the characters in the character array */
void reverse(char to_reverse[], int limit);

/* swaps the characters at the positions specified */
void swap(char array[], int pos_1, int pos_2);

int main()
{
    // char string_1[45] = "This string is now reversed with a new line!\n";
    // char string_2[46] = "This string is now reversed with a null byte!\0";
    // reverse(string_1, 45);
    // reverse(string_2, 46);
    // printf("%s", string_1);
    // printf("%s\n", string_2); 

    int c, i, j;
    char cur_line[MAX_LINE_LENGTH];

    i = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            if (i > 0 && i <= MAX_LINE_LENGTH - 1) {
                reverse(cur_line, i);
                for (j = 0; j < i; ++j) {
                    putchar(cur_line[j]);
                }
                putchar('\n');
            }
            i = 0;
        } else {
            cur_line[i] = c;
            ++i;
        }
    }
}

void reverse(char to_reverse[], int limit)
{
    int i;
    for (i = 0; i <= ((limit - 1) / 2); ++i) {
        swap(to_reverse, i, limit - 1 - i);
    }
}

void swap(char array[], int pos_1, int pos_2)
{
    char temp = array[pos_1];
    array[pos_1] = array[pos_2];
    array[pos_2] = temp;
}