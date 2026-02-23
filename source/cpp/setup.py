from setuptools import setup, Extension
from Cython.Build import cythonize

# 🔧 Define the C++ extension module
ext = Extension(
    name='solution',              # 📦 Name of the compiled module (import as: import solution)
    sources=['solution.pyx'],     # 🐍 Cython source file
    language='c++'                # ⚙️ Compile as C++ (REQUIRED for libcpp / cppclass)
)

# 🚀 Build configuration
setup(
    ext_modules=cythonize(
        ext,
        language_level=3          # 🐍 Use Python 3 syntax rules
    )
)