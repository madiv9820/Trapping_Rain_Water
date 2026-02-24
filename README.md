# 🌧️ Trapping Rain Water — Brute Force Approach

### 🧠 Problem Overview
Given an array `height[]` representing elevation bars, compute how much rainwater can be trapped after raining.

Each bar’s trapped water depends on:
- The tallest bar on its **left**
- The tallest bar on its **right**

Water level at any index is limited by the **shorter boundary**.

### 💡 Brute Force Strategy

For every index:
1. 🔍 Scan left to find `leftMax`
2. 🔎 Scan right to find `rightMax`
3. 💧 Water trapped at index: `min(leftMax, rightMax) - height[i]`
4. Add it to total water (if positive)

Simple. Clear. Straightforward. <br>
Not the fastest — but very intuitive.

### 🧱 Visual Intuition
```
Height:  [0,1,0,2,1,0,1,3,2,1,2,1]

At index 2:
Left max  = 1
Right max = 3
Water     = min(1,3) - 0 = 1
```
Water is trapped because taller bars exist on both sides 🌊

### ⚙️ Implementation Logic
- Skip first and last bars (no boundary on both sides 🚫)
- For each bar:
    - Traverse left
    - Traverse right
- Compute trapped water
- Accumulate total

### ⏱️ Complexity Analysis
- #### 🕒 Time Complexity: O(n²) <br>
    For every element, we scan:
    - Left side → O(n)
    - Right side → O(n)
    
    Total → **O(n × n) = O(n²)**

- #### 🧠 Space Complexity: O(1) <br>
    Only a few variables used:
    - `leftMax`
    - `rightMax`  
    - `waterTrapped`

    No extra arrays needed.

### 🎯 Why Use Brute Force?
- ✅ Easy to understand <br>
- ✅ Great starting point for interviews <br>
- ✅ Builds intuition for optimized solutions

### 🚀 Next Optimization

This solution can be improved to:
- **O(n)** using Two Pointers
- **O(n)** using Prefix & Suffix arrays

But first — understand the brute force deeply. <br>
Optimization comes after clarity ✨

---