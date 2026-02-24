from typing import List

class pySolution:
    def py_trap(self, height: List[int]) -> int:
        # 🌊 This will store the total amount of trapped rainwater
        waterTrapped: int = 0

        # 📏 Total number of elevation bars
        n: int = len(height)

        # 🚫 First and last bars can't trap water, so we skip them
        for currentPosition in range(1, n - 1):

            # 🧱 Track the tallest bar on the left and right
            leftMax: int = -1
            rightMax: int = -1

            # 🔍 Find the tallest bar to the LEFT
            for prevPosition in range(currentPosition - 1, -1, -1):
                leftMax = max(leftMax, height[prevPosition])
            
            # 🔎 Find the tallest bar to the RIGHT
            for nextPosition in range(currentPosition + 1, n):
                rightMax = max(rightMax, height[nextPosition])

            # 💧 Water trapped at this position:
            # Limited by the smaller of leftMax and rightMax
            # Subtract current height to get stored water
            # If negative, add 0 (no water trapped here)
            waterTrapped += max(0, min(leftMax, rightMax) - height[currentPosition])

        # 🎉 Return the total accumulated water
        return waterTrapped