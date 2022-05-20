#include <assert.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mat_print(float *const restrict m,
               size_t const n)
{
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            printf("%0.0f ", m[i * n + j]);
        }
        printf("\n");
    }
    printf("\n");
}

void mm2(float const *const restrict a,
         float const *const restrict b,
         float *const restrict c,
         size_t const n)
{
    register float const a00 = a[0];
    register float const a01 = a[1];
    register float const a10 = a[n];
    register float const a11 = a[n + 1];
    register float const b00 = b[0];
    register float const b01 = b[1];
    register float const b10 = b[n];
    register float const b11 = b[n + 1];
    register float c00 = c[0];
    register float c01 = c[1];
    register float c10 = c[n];
    register float c11 = c[n + 1];
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
    c[n] = c10;
    c[n + 1] = c11;
}

void mm(float const *const restrict a,
        float const *const restrict b,
        float *const restrict c,
        size_t const n)
{
    for (size_t i = 0; i < n; i += 2)
    {
        for (size_t k = 0; k < n; k += 2)
        {
            for (size_t j = 0; j < n; j += 2)
            {
                mm2(a + (n * i + k), b + (n * k + j), c + (i * n + j), n);
            }
        }
    }
}

int main(int const argc, char const *const *const argv)
{
    float *A = NULL;
    float *B = NULL;
    float *C = NULL;
    for (size_t n = 2; n < 65536; n *= 2)
    {
        if (A)
        {
            free(A);
        }
        A = (float *)(malloc(n * n * sizeof(float)));
        assert(A);
        if (B)
        {
            free(B);
        }
        B = (float *)(malloc(n * n * sizeof(float)));
        assert(B);
        for (size_t i = 0; i < n * n; ++i)
        {
            A[i] = i + 1;
            B[i] = (n * n) - i;
        }
        if (C)
        {
            free(C);
        }
        C = (float *)(calloc(n * n, sizeof(float)));
        assert(C);
        clock_t const ti = clock();
        mm(A, B, C, n);
        clock_t const tf = clock();
        double const dur_s = (tf - ti) / CLOCKS_PER_SEC;
        double const gflops = (n * n * n * 2.0) / (1e9 * dur_s);
        printf("%lu, %f, %f\n", n, dur_s, gflops);
    }
    return 0;
}
