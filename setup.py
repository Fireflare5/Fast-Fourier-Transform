from setuptools import setup, Extension
from Cython.Build import cythonize
import numpy

extensions = [
    Extension(
        name="FFT.core",
        sources=["src/FFT/core.pyx"],
        include_dirs=["src/FFT", numpy.get_include()],
        extra_compile_args=["-O3"],
    )
]

setup(
    ext_modules=cythonize(extensions)
)