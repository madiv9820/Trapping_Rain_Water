#ifndef SOLUTION_H
#define SOLUTION_H

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

#include <stdlib.h>

int trap(int* height, int heightSize) {
    // 🌊 Total trapped rainwater
    int waterTrapped = 0;
    
    // 🔢 Index and stack variables
    int currentIndex;
    int topIndex;        // 🧱 Top of the stack
    int bottom;          // ⬇️ Index of the bottom of a container
    int left;            // ⬅️ Left boundary index
    int right;           // ➡️ Right boundary index
    int width;           // ↔️ Width of trapped water
    int boundedHeight;   // 📏 Height of trapped water at this segment
    int *stack = NULL;   // 📚 Stack to keep indices of bars

    // ✅ Only process if array is non-empty
    if(heightSize > 0) {
        stack = calloc(heightSize, sizeof(int)); // 🧰 Allocate stack
        topIndex = -1;  // 🔹 Initialize empty stack

        // 🔄 Iterate through each bar
        for(currentIndex = 0; currentIndex < heightSize; ++currentIndex) {

            // ⚠️ While current bar is taller than top of stack
            while(topIndex >= 0 && height[currentIndex] > height[stack[topIndex]]) {
                // ⬇️ Pop the top element as the bottom of a container
                bottom = stack[topIndex--];

                // ❌ No left boundary → cannot trap water
                if(topIndex == -1) break;
                
                // 🧱 Define left and right boundaries
                right = currentIndex;
                left = stack[topIndex];

                // ↔️ Width between boundaries
                width = right - left - 1;

                // 📏 Bounded height is limited by shorter boundary minus bottom
                boundedHeight = MAX(
                    0,
                    MIN(height[left], height[right]) - height[bottom]
                );
                
                // 💧 Add trapped water for this segment
                waterTrapped += (boundedHeight * width);
            }

            // 📚 Push current index onto the stack
            stack[++topIndex] = currentIndex;
        }

        // 🧹 Free allocated stack
        free(stack);
    }

    // 🎉 Return total trapped rainwater
    return waterTrapped;
}

#endif