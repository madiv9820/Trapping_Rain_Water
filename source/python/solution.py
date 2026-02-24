from typing import List

class pySolution:
    def py_trap(self, height: List[int]) -> int:
        # 🌊 Total trapped rainwater
        waterTrapped: int = 0

        n: int = len(height)

        # Edge case: if no bars exist, no water can be trapped
        if n > 0:
            # ⬅️ Left pointer, ➡️ Right pointer
            left: int = 0
            right: int = n - 1

            # 🧱 Max heights seen so far from left and right
            leftMax: int = 0
            rightMax: int = 0

            # 🚀 Iterate until pointers meet
            while left < right:
                if height[left] < height[right]:
                    # 🔹 Current left bar is shorter
                    if height[left] > leftMax:
                        # Update leftMax if current bar is taller
                        leftMax = height[left]
                    else:
                        # Water trapped = leftMax - current height
                        waterTrapped += (leftMax - height[left])
                    left += 1  # Move left pointer rightwards
                else:
                    # 🔹 Current right bar is shorter or equal
                    if height[right] > rightMax:
                        # Update rightMax if current bar is taller
                        rightMax = height[right]
                    else:
                        # Water trapped = rightMax - current height
                        waterTrapped += (rightMax - height[right])
                    right -= 1  # Move right pointer leftwards

        # 🎉 Return total trapped water
        return waterTrapped