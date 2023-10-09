#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary_search(int x, int v[], int n);
int binary_search2(int target_value, int target_array[], int array_length);

int main()
{
    printf("Initialising array.\n");
    const int SORTED_ARRAY_SIZE = 1000000;
    int i, sorted_array[SORTED_ARRAY_SIZE];
    sorted_array[0] = 0;
    for (i = 1; i < SORTED_ARRAY_SIZE; ++i)
        sorted_array[i] = sorted_array[i - 1] + rand() % 5;
    printf("Array of %d elements initialised.\n", SORTED_ARRAY_SIZE);

    const int value_to_find = sorted_array[SORTED_ARRAY_SIZE / 3]; /* picked this number randomly for consistency */
    int found_location;

    printf("Benchmarking binary_search.\n");
    clock_t bin_1_begin = clock();

    found_location = binary_search(value_to_find, sorted_array, SORTED_ARRAY_SIZE);

    clock_t bin_1_end = clock();
    printf("Found value %d in position %d.\n", value_to_find, found_location);
    printf("Clock time for binary_1: %03.16fms (16 d.p.)\n", (bin_1_end - bin_1_begin) / (float)CLOCKS_PER_SEC * 1000);

    printf("Benchmarking binary_search2.\n");
    clock_t bin_2_begin = clock();

    found_location = binary_search2(value_to_find, sorted_array, SORTED_ARRAY_SIZE);

    clock_t bin_2_end = clock();
    printf("Found value %d in position %d.\n", value_to_find, found_location);
    printf("Clock time for binary_2: %03.16fms (16 d.p.)\n", (bin_2_end - bin_2_begin) / (float)CLOCKS_PER_SEC * 1000);
}

/* binary_search: find x in v[0] <= v[1] <= ... <= v[n-1]*/
int binary_search(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return mid;
    }
    return -1; /* no match */
}

/* binary_search2: find x in v[0] <= v[1] <= ... <= v[n-1]*/
int binary_search2(int target_value, int target_array[], int array_length)
{
    int low, high, mid;

    low = 0;
    high = array_length - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (target_value < target_array[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    mid = (low + high) / 2;
    if (target_array[mid] == target_value)
        return mid;
    return -1;
}