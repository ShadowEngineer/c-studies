#include <stdio.h>
/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */

float to_celsius(int f)
{
    return ((5.0/9.0) * (f - 32.0));
}

float to_fahrenheit(int c)
{
    return ((9.0/5.0) * c + 32.0);
}

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;      // the lower limit of the temperature scale
    upper = 300;    // the higher limit of the temperature scale
    step = 20;      // the incremental steps of temperature between each iteration

    printf("From Fahrenheit to Celsius:\n");
    fahr = lower;
    while (fahr <= upper) {
        celsius = to_celsius(fahr);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr += step;
    }

    printf("From Celsius to Fahrenheit:\n");
    celsius = lower;
    while (celsius <= upper) {
        fahr = to_fahrenheit(celsius);
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius += step;
    }
}
