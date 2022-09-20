#include <stdio.h>
/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      // the lower limit of the temperature scale
    upper = 300;    // the higher limit of the temperature scale
    step = 20;      // the incremental steps of temperature between each iteration

    printf("Fahrenheit first:\n");
    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr += step;
    }

    printf("Celsius second:\n");
    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius += step;
    }
}