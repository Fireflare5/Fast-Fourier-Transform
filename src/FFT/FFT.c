#include <complex.h> 
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "FFT.h"

static void ReverseBit(double complex *__restrict p, size_t n)
{
    size_t i, j, k;
    j = 0;
    for (i = 0; i < n; ++i)
    {
        if (i <= j)
        {
            double complex temp = p[i];
            p[i] = p[j];
            p[j] = temp;
        }

        k = n >> 1;

        while (k && k <= j)
        {
            j -= k;
            k >>= 1;
        }

        j += k;
    }
}

void FFT(double complex *__restrict p, size_t n, short invert)
{
    size_t len, i, j;

    ReverseBit(p, n);

    for (len = 2; len <= n; len <<= 1)
    {
        double ang = 2.0 * M_PI / len * (invert ? -1 : 1);
        double complex wlen = cos(ang) + I * sin(ang);
        for (i = 0; i < n; i += len)
        {
            double complex w = 1.0 + I * 0.0;
            for (j = 0; j < len / 2; ++j)
            {
                long complex u = p[i + j];
                long complex v = w * p[i + j + len / 2];
                p[i + j] = u + v;
                p[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert)
    {
        for (i = 0; i < n; ++i)
        {
            p[i] /= n;
        }
    }
}