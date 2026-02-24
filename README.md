# 🌊 Trapping Rain Water — Two-Pointer Optimized Approach
### 🧠 Problem Overview
Given an elevation map `height[]`, compute how much rainwater can be trapped after raining.

Water trapped at each position depends on:
- 🧱 The tallest bar on the **left**
- 🧱 The tallest bar on the **right**

The water level at any position is limited by the **shorter of the two boundaries**.

### 💡 Key Insight
Instead of scanning left and right for every index (like brute-force), we can **use two pointers** to traverse the array once, keeping track of maximum boundaries seen so far.

Water at index `i` is: `water[i] = min(leftMax, rightMax) - height[i]`

### 🔹 How the Two-Pointer Algorithm Works
1. Initialize two pointers:
    - left at the start of the array
    - right at the end of the array
2. Track tallest bars so far from both sides:
    - leftMax for the left
    - rightMax for the right
3. At each step, move the pointer with the shorter height:
    - If height[left] < height[right] → move left pointer
    - Else → move right pointer
4. Calculate trapped water for that pointer: `waterTrapped += max(0, maxSoFar - currentHeight)`
5. Repeat until pointers meet.

### 🧱 Example
```
Height:  [0,1,0,2,1,0,1,3,2,1,2,1]

Step: index 2
leftMax  = 1
rightMax = 3
Water    = min(1,3) - 0 = 1
```

### ⏱️ Complexity Analysis
- **Time Complexity:** `O(n)` — single pass over the array
- **Space Complexity:** `O(1)` — no extra arrays, only a few variables

### 🔥 Why This Approach Is Great
- ✅ Most optimized for both time and space
- ✅ Simple to reason about once you understand pointers
- ✅ Perfect for interviews and competitive programming

---