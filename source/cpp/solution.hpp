#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // 🌊 This will store the total amount of trapped rainwater
        int waterTrapped = 0;

        // 📏 Total number of bars
        int n = height.size();

        // 🚫 First and last bars can't trap water, so we skip them
        for (int currentPosition = 1; currentPosition < n - 1; ++currentPosition) {

            // 🧱 These will track the tallest bar to the left and right
            int leftMax = -1;
            int rightMax = -1;

            // 🔍 Find the tallest bar on the LEFT
            for (int prevPosition = currentPosition - 1; prevPosition >= 0; --prevPosition)
                leftMax = max(leftMax, height[prevPosition]);

            // 🔎 Find the tallest bar on the RIGHT
            for (int nextPosition = currentPosition + 1; nextPosition < n; ++nextPosition)
                rightMax = max(rightMax, height[nextPosition]);

            // 💧 Water trapped at this position:
            // It is limited by the smaller of leftMax and rightMax
            // Subtract the current bar height to get stored water
            // If negative, we add 0 (no water trapped)
            waterTrapped += max(0, min(leftMax, rightMax) - height[currentPosition]);
        }

        // 🎉 Return total trapped water
        return waterTrapped;
    }
};

#endif