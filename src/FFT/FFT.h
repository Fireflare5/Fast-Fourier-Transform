#include <complex.h>
#include <stdbool.h>

#ifndef FFT_H
#define FFT_H

static void ReverseBit(double complex *__restrict p, size_t n);

void FFT(double complex *__restrict p, size_t n, short invert);

#endif