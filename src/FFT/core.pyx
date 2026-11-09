
cdef extern from "FFT.c":
    pass

cdef extern from "FFT.h":
    void FFT(double complex *p, size_t n, short invert)

import numpy as np

def fft(p, bool inverse):
    """
    Fast Fourier Transform

    Args:
        p (np.ndarray): Input Array
        invert (bool, optional): Inverse Fast Fourier Transform? Defaults to False.

    Returns:
        np.ndarray: Array of complex values
    """

    pow = np.log2(p.shape[0])
    if pow < np.ceil(pow):
        print("Error: Invalid size (Size must be a power of 2)")
        return None

    cdef size_t n = p.shape[0]

    cdef double complex[::1] v = np.asarray(p, dtype=np.complex128)

    cdef double complex *P = &v[0]

    FFT(P, n, inverse)

    cdef double complex[:] out = <double complex[:n]> P

    return np.asarray(out)
