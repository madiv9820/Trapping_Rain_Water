#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // 🌊 Total trapped rainwater
        int waterTrapped = 0;

        int n = height.size();

        // Edge case: if no bars exist, no water can be trapped
        if (n > 0) {
            // ⬅️ Left pointer, ➡️ Right pointer
            int left = 0;
            int right = n - 1;

            // 🧱 Max heights seen so far from left and right
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

        // 🎉 Return total trapped water
        return waterTrapped;
    }
};

#endif