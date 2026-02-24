from typing import List, Deque
from collections import deque

class pySolution:
    def py_trap(self, height: List[int]) -> int:
        # 🌊 Total trapped rainwater
        waterTrapped: int = 0
        
        n: int = len(height)

        # ✅ Only process if array is non-empty
        if n > 0:
            stack: Deque = deque()  # 📚 Monotonic stack storing indices

            # 🔄 Iterate through each bar
            for currentIndex in range(n):

                # ⚠️ While current bar is taller than the bar at top of stack
                while len(stack) > 0 and height[currentIndex] > height[stack[0]]:
                    # ⬇️ Pop top element as the bottom of a container
                    bottom: int = stack.popleft()

                    # ❌ No left boundary → cannot trap water
                    if len(stack) == 0: 
                        break

                    # ⬅️↔️➡️ Determine left and right boundaries
                    left: int = stack[0]
                    right: int = currentIndex

                    # ↔️ Width between boundaries
                    width: int = right - left - 1

                    # 📏 Height of trapped water is limited by shorter boundary minus bottom
                    boundedHeight: int = max(
                        0,
                        min(height[left], height[right]) - height[bottom]
                    )

                    # 💧 Add water trapped in this segment
                    waterTrapped += (width * boundedHeight)
                    
                # 📚 Push current index onto the stack
                stack.appendleft(currentIndex)
            
            # 🧹 Cleanup (optional, Python GC handles this)
            del stack

        # 🎉 Return total trapped rainwater
        return waterTrapped