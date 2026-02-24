#ifndef SOLUTION_H
#define SOLUTION_H

// Utility macros for cleaner min/max operations 🔧
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#include <stdlib.h>

int trap(int* height, int heightSize) {
    // 🌊 Stores total accumulated trapped rainwater
    int waterTrapped = 0;
    
    // Edge case: no bars → no water
    if (heightSize > 0) {

        // 📦 Allocate memory for prefix (leftMax) and suffix (rightMax) arrays
        // leftMax[i]  = tallest bar from index 0 → i
        // rightMax[i] = tallest bar from index i → n-1
        int *leftMax = calloc(heightSize, sizeof(int));
        int *rightMax = calloc(heightSize, sizeof(int));
        int currentIndex;

        // 🧱 Initialize boundary values
        leftMax[0] = height[0];  
        rightMax[heightSize - 1] = height[heightSize - 1];

        // 👉 Build leftMax array (prefix maximum)
        // Each position stores the tallest bar seen so far from the left
        for (currentIndex = 1; currentIndex < heightSize; ++currentIndex) {
            leftMax[currentIndex] = MAX(
                leftMax[currentIndex - 1], 
                height[currentIndex]
            );
        }

        // 👈 Build rightMax array (suffix maximum)
        // Each position stores the tallest bar seen so far from the right
        for (currentIndex = heightSize - 2; currentIndex >= 0; --currentIndex) {
            rightMax[currentIndex] = MAX(
                rightMax[currentIndex + 1], 
                height[currentIndex]
            );
        }

        // 💧 Calculate trapped water at each index
        // Water level is limited by the shorter of leftMax[i] and rightMax[i]
        for (currentIndex = 0; currentIndex < heightSize; ++currentIndex) {
            waterTrapped += MAX(
                0,  // Avoid negative water
                MIN(
                    leftMax[currentIndex], 
                    rightMax[currentIndex]
                ) - height[currentIndex]
            );
        }

        // 🧹 Free dynamically allocated memory
        free(leftMax);
        free(rightMax);
    }
    
    // 🎉 Return total trapped rainwater
    return waterTrapped;
}

#endif