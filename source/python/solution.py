from typing import List

class pySolution:
    def py_trap(self, height: List[int]) -> int:
        # 🌊 Stores total accumulated trapped rainwater
        waterTrapped: int = 0

        n: int = len(height)

        # Edge case: no bars → no trapped water
        if n > 0:

            # 📦 leftMax[i]  = tallest bar from index 0 → i
            # 📦 rightMax[i] = tallest bar from index i → n-1
            leftMax: List[int] = [0] * n
            rightMax: List[int] = [0] * n

            # 🧱 Initialize boundary values
            leftMax[0] = height[0]
            rightMax[n - 1] = height[n - 1]

            # 👉 Build prefix maximum array (left → right)
            # Each position stores the tallest bar seen so far
            for currentIndex in range(1, n):
                leftMax[currentIndex] = max(
                    leftMax[currentIndex - 1],
                    height[currentIndex]
                )

            # 👈 Build suffix maximum array (right → left)
            # Each position stores the tallest bar seen from the right
            for currentIndex in range(n - 2, -1, -1):
                rightMax[currentIndex] = max(
                    rightMax[currentIndex + 1],
                    height[currentIndex]
                )

            # 💧 Calculate trapped water at each index
            # Water level is limited by the shorter boundary
            for currentIndex in range(n):
                waterTrapped += max(
                    0,  # Prevent negative contribution
                    min(
                        leftMax[currentIndex],
                        rightMax[currentIndex]
                    ) - height[currentIndex]
                )

            # 🧹 Explicit cleanup (optional; Python GC handles this)
            del leftMax
            del rightMax

        # 🎉 Return total trapped rainwater
        return waterTrapped