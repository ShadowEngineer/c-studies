#include <stdio.h>
/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */

int main()
{
    int fahr, celsius;
    int lower, upper, step;

    lower = 0;      // the lower limit of the temperature scale
    upper = 300;    // the higher limit of the temperature scale
    step = 20;      // the incremental steps of temperature between each iteration

    printf("Fahrenheit first:\n");
    fahr = lower;
    while (fahr <= upper) {
        celsius = 5 * (fahr - 32) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }

    printf("Celsius second:\n");
    celsius = lower;
    while (celsius <= upper) {
        fahr = 9 * celsius / 5 + 32;
        printf("%d\t%d\n", celsius, fahr);
        celsius = celsius + step;
    }
}