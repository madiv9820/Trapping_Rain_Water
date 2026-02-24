from libcpp.vector cimport vector  # 📦 Import C++ std::vector

# 🔗 Declare the external C++ class from solution.hpp
cdef extern from "solution.hpp":
    cdef cppclass Solution:
        Solution() except +              # 🏗️ Constructor (propagates C++ exceptions)
        int trap(vector[int]& height)    # 💧 Method to compute trapped rain water


# 🧩 Cython wrapper class around the C++ Solution
cdef class cppSolution:
    cdef Solution* ptr   # 📌 Pointer to C++ Solution instance

    def __init__(self):
        # 🚀 Allocate new C++ Solution object
        self.ptr = new Solution()

    def __dealloc__(self):
        # 🧹 Clean up C++ object to prevent memory leaks
        if self.ptr is not NULL:
            del self.ptr

    def cpp_trap(self, height):
        """
        🌉 Bridge method:
        Converts Python list -> C++ std::vector<int>
        Then calls the C++ trap() implementation.
        """
        cdef vector[int] heightArray   # 📦 Create C++ vector
        cdef int i

        # 🔄 Copy elements from Python list into C++ vector
        for i in range(len(height)):
            heightArray.push_back(height[i])

        # 💧 Call the C++ solution and return result to Python
        return self.ptr.trap(heightArray)