#ifndef SOLUTION_H
#define SOLUTION_H

int trap(int* height, int heightSize) {
    // 🌊 Total amount of trapped rainwater
    int waterTrapped = 0;

    // Edge case: no bars → no trapped water
    if (heightSize > 0) {
        // ⬅️ Left pointer, ➡️ Right pointer
        int left = 0;
        int right = heightSize - 1;

        // 🧱 Max walls seen so far from left and right
        int leftMax = 0;
        int rightMax = 0;

        // 🚀 Iterate until the two pointers meet
        while (left < right) {
            if (height[left] < height[right]) {
                // 🔹 Current left bar is shorter
                if (height[left] > leftMax) {
                    // Update leftMax if current bar is taller
                    leftMax = height[left];
                } else {
                    // Water trapped = leftMax - current height
                    waterTrapped += (leftMax - height[left]);
                }
                ++left;  // Move left pointer rightwards
            } 
            else {
                // 🔹 Current right bar is shorter or equal
                if (height[right] > rightMax) {
                    // Update rightMax if current bar is taller
                    rightMax = height[right];
                } else {
                    // Water trapped = rightMax - current height
                    waterTrapped += (rightMax - height[right]);
                }
                --right;  // Move right pointer leftwards
            }
        }
    }

    // 🎉 Return total trapped rainwater
    return waterTrapped;
}

#endif