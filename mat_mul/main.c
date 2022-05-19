#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void mm2(float const * const restrict a,
         float const * const restrict b,
         float * const restrict c)
{
    register float const a00 = a[0];
    register float const a01 = a[1];
    register float const a10 = a[2];
    register float const a11 = a[3];
    register float const b00 = b[0];
    register float const b01 = b[1];
    register float const b10 = b[2];
    register float const b11 = b[3];
    register float c00 = c[0];
    register float c01 = c[1];
    register float c10 = c[2];
    register float c11 = c[3];
    c00 += a00 * b00;
    c00 += a01 * b10;
    c01 += a00 * b01;
    c01 += a01 * b11;
    c10 += a10 * b00;
    c10 += a11 * b10;
    c11 += a10 * b01;
    c11 += a11 * b11;
    c[0] = c00;
    c[1] = c01;
    c[2] = c10;
    c[3] = c11;
}

int main(int const argc, char const * const * const argv)
{
    float A[] = { 1, 2, 3, 4 };
    float B[] = { 4, 3, 2, 1 };
    float C[] = { 0, 0, 0, 0 };
    mm2(A, B, C);
    for(size_t i = 0; i < 4; ++i)
    {
        printf("%f\n", C[i]);
    }
    return 0;
}
