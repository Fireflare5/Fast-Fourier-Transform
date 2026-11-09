import numpy as np
import numpy.typing as types
def fft(p: types.NDArray, inverse: bool)->types.NDArray[np.complex128]:
    """
    Fast Fourier Transform

    Parameters
    ----------
        p : array_like
            Array of size k^2
        invert : bool
            Inverse Fast Fourier Transform? Defaults to False.

    Returns
    -------
        out : ndarray
            Complex array of the same shape as p.
    """