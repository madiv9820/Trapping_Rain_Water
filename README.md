# 🌧️ Trapping Rain Water — Prefix/Suffix (DP) Approach

### 🧠 Problem Overview

Given an elevation map represented by an array `height[]`, compute how much rainwater can be trapped after raining.
Each index can trap water depending on:
- 🧱 The tallest bar on its **left**
- 🧱 The tallest bar on its **right**

The water level at any position is limited by the **shorter boundary**.

### 💡 Key Insight
For every index `i`:  `water[i] = min(maxLeft[i], maxRight[i]) - height[i]`

Instead of recalculating left and right maximums repeatedly (like in brute force),
we **precompute them once** using two arrays.
This reduces time complexity from **O(n²) ➝ O(n)** 🚀

### 📦 Approach Breakdown

**1️⃣. Build Prefix Max Array (`leftMax`)** <br>
`leftMax[i]` stores the tallest bar from index `0` to `i`. <br>
`leftMax[i] = max(leftMax[i - 1], height[i])`

**2️⃣ Build Suffix Max Array (`rightMax`)** <br>
`rightMax[i]` stores the tallest bar from index `i` to `n - 1`. <br>
`rightMax[i] = max(rightMax[i + 1], height[i])`

**3️⃣ Compute Trapped Water 💧** <br>
For each index: <br>
`water += max(0, min(leftMax[i], rightMax[i]) - height[i])`

### 🧱 Example
```
Height:  [0,1,0,2,1,0,1,3,2,1,2,1]

Index 2:
leftMax  = 1
rightMax = 3
Water    = min(1,3) - 0 = 1
```
Water gets trapped because taller walls exist on both sides 🌊

### ⏱️ Complexity Analysis
- **🕒 Time Complexity: O(n)**
    - 1 pass to build `leftMax`
    - 1 pass to build `rightMax`
    - 1 pass to compute water

    Total → **3n ≈ O(n)**

- **🧠 Space Complexity: O(n)**
    - leftMax array → O(n)
    - rightMax array → O(n)

    Extra memory is used to eliminate repeated scanning.

### 🔥 Why This Is Better Than Brute Force
| **Approach**      | **Time**  | **Space** |
| ------------- | ----- | ----- |
| Brute Force   | `O(n²)` | `O(1)`  |
| Prefix/Suffix | `O(n)`  | `O(n)`  |

### 🚀 What’s Next?
You can optimize even further:
- 🔄 Two-pointer approach
- ⬇️ Reduce space complexity to **O(1)**

But this DP method is:
- Clean
- Efficient
- Interview-friendly
- Easy to reason about

---