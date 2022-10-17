#include <stdio.h>

int rand(void);
void srand(unsigned int seed);

unsigned long int next = 1;

int main()
{
    for (int n = next; n <= 5; n++) {
        printf("SEED: %d", n);
        srand(n);
        for (int i = 0; i < 10; ++i)
            printf("%d\n", rand());
    }
}

int rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

void srand(unsigned int seed)
{
    next = seed;
}