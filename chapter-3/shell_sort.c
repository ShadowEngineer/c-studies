#include <stdio.h>

void shellsort(int v[], int n);
void print_array(int arr[], int arr_len);

int main()
{
    const unsigned int length = 10;
    int array[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    printf("Before sorting:\n");
    print_array(array, length);
    shellsort(array, length);
    printf("After sorting:\n");
    print_array(array, length);
    return 0;
}

void shellsort(int v[], int n)
{
    int gap, i, j, temp;
    for (gap = n / 2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
            {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
}

void print_array(int arr[], int arr_len)
{
    for (int i = 0; i < arr_len; i++)
        printf("[%d]: %d\n", i, arr[i]);
}