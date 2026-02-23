from libc.stdlib cimport calloc, free  # 🧰 C standard library functions for memory management

# 🔗 Declare external C function from solution.h
cdef extern from "solution.h":
    int trap(int *height, int heightSize)  # 💧 Function to compute trapped rain water

# 🧩 Cython wrapper class around the C implementation
cdef class cSolution:

    def c_trap(self, height):
        """
        🌉 Bridge method:
        Converts Python list -> C array (int*) 
        Calls the C trap() function and returns the result.
        """
        cdef int n = len(height)    # 📏 Length of the input array
        cdef int i

        # ⚠️ Allocate memory for C array, initialized to zero
        cdef int* heightArray = <int*> calloc(n, sizeof(int))
        if heightArray == NULL:
            raise MemoryError("Memory Allocation Failed")  # 🚨 Handle allocation failure
        
        try:
            # 🔄 Copy Python list elements into the C array
            for i in range(n):
                heightArray[i] = height[i]
            
            # 💧 Call the C implementation
            return trap(heightArray, n)
        finally:
            # 🧹 Free allocated memory to prevent leaks
            free(heightArray)