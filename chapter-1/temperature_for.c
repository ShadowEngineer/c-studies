#include <stdio.h>
/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */

#define LOWER 0     // the lower limit of the Fahrenheit scale
#define UPPER 300   // the upper limit of the Fahrenheit scale
#define STEP 20     // the step between each increment of the Fahrenheit scale

int main()
{
    int fahr;

    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP)
        printf("%3d %6.1f\n", fahr, (5.0 /9.0 * (fahr - 32.0)));
}