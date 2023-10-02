#include <stdio.h>

#define NUMBER_OF_YEARS 2100
enum BOOL
{
    FALSE,
    TRUE,
};

int is_leap_year(int year);

int main()
{
    int current_year;
    for (current_year = 0; current_year <= NUMBER_OF_YEARS; current_year++)
        if (is_leap_year(current_year) == TRUE)
            printf("Year %d is a leap year!\n", current_year);
}

int is_leap_year(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return TRUE;
    else
        return FALSE;
}