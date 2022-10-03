#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    // every possible combination of type identifiers
    int a;                  // 4 bytes
    short int b;            // 2 bytes
    long int c;             // 8 bytes
    unsigned int d;         // 4 bytes
    unsigned short int e;   // 2 bytes
    unsigned long int f;    // 8 bytes
    signed int g;           // 4 bytes
    signed short int h;     // 2 bytes
    signed long int i;      // 8 bytes

    char j;                 // 1 byte
    unsigned char k;        // 1 byte
    signed char l;          // 1 byte

    float m;                // 4 bytes
    double n;               // 8 bytes
    long double o;          // 16 bytes
    return 0;
}