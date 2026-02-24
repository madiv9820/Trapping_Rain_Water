#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // 🌊 Stores the total accumulated trapped rainwater
        int waterTrapped = 0;
        
        int n = height.size();

        // Edge case: if no bars exist, no water can be trapped
        if (n > 0) {

            // 📦 leftMax[i]  = tallest bar from index 0 → i
            // 📦 rightMax[i] = tallest bar from index i → n-1
            vector<int> leftMax(n, 0);
            vector<int> rightMax(n, 0);

            // 🧱 Initialize boundary values
            leftMax[0] = height[0];
            rightMax[n - 1] = height[n - 1];

            // 👉 Build prefix maximum array (left to right)
            // Each position keeps track of the tallest bar seen so far
            for (int currentIndex = 1; currentIndex < n; ++currentIndex) {
                leftMax[currentIndex] = max(
                    leftMax[currentIndex - 1], 
                    height[currentIndex]
                );
            }

            // 👈 Build suffix maximum array (right to left)
            // Each position keeps track of the tallest bar seen from the right
            for (int currentIndex = n - 2; currentIndex >= 0; --currentIndex) {
                rightMax[currentIndex] = max(
                    rightMax[currentIndex + 1],
                    height[currentIndex]
                );
            }

            // 💧 Calculate trapped water at each index
            // Water level is limited by the shorter of leftMax[i] and rightMax[i]
            for (int currentIndex = 0; currentIndex < n; ++currentIndex) {
                waterTrapped += max(
                    0,  // Prevent negative contribution
                    min(
                        leftMax[currentIndex], 
                        rightMax[currentIndex]
                    ) - height[currentIndex]
                );
            }

            // 🧹 Explicitly free memory (optional; vectors auto-clean)
            vector<int>().swap(leftMax);
            vector<int>().swap(rightMax);
        }

        // 🎉 Return total trapped rainwater
        return waterTrapped;
    }
};

#endif