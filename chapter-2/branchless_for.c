#include <stdio.h>

int main()
{
    int i;
    int lim = 1000;
    char c;
    char s[lim];

    // old
    // for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
    //     s[i] = c;
    // }

    // branchless
    for (i = 0; (i < lim - 1); ++i) {
        if ((c = getchar()) != '\n') {
            if (c != EOF) {
                s[i] = c;
            }
        }
    }

    return 0;
}