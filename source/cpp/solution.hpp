#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        // 🌊 Total trapped rainwater
        int waterTrapped = 0;

        int n = height.size();

        // ✅ Only process if array is non-empty
        if(n > 0) {
            stack<int> st;  // 📚 Monotonic stack storing indices

            // 🔄 Iterate through each bar
            for(int currentIndex = 0; currentIndex < n; ++currentIndex) {

                // ⚠️ While current bar is taller than the bar at top of stack
                while(!st.empty() && height[currentIndex] > height[st.top()]) {
                    // ⬇️ Pop top element as the bottom of a container
                    int bottom = st.top();
                    st.pop();

                    // ❌ No left boundary → cannot trap water
                    if(st.empty()) break;

                    // ⬅️↔️➡️ Determine left and right boundaries
                    int left = st.top();
                    int right = currentIndex;

                    // ↔️ Width between boundaries
                    int width = right - left - 1;

                    // 📏 Height of trapped water is limited by shorter boundary minus bottom
                    int boundedHeight = max(
                        0,
                        min(height[left], height[right]) - height[bottom]
                    );

                    // 💧 Add water trapped in this segment
                    waterTrapped += (width * boundedHeight);
                }

                // 📚 Push current index onto the stack
                st.push(currentIndex);
            }

            // 🧹 Clear stack (optional, for cleanup)
            stack<int>().swap(st);
        }

        // 🎉 Return total trapped rainwater
        return waterTrapped;
    }
};

#endif