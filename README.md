# 🌊 Trapping Rain Water — Stack-Based Approach
### 🧠 Problem Overview
Given an elevation map represented by an array `height[]`, compute how much rainwater can be trapped after raining.

Water trapped at each position depends on:
- 🧱 The tallest bar to the **left**
- 🧱 The tallest bar to the **right**

The water level is limited by the **shorter of the two boundaries**.

### 💡 Key Insight
Instead of checking left and right boundaries for **every bar** (O(n²) brute-force) or using extra arrays (O(n) space DP), we can use a **monotonic stack**:
- The stack keeps track of **indices of bars in decreasing height**.
- When a taller bar arrives, we **pop shorter bars**, forming "containers" to trap water.
- Each popped bar represents the **bottom of a water trap**, and the current bar forms the **right boundary**.

### 🔹 How the Stack Algorithm Works
1. Initialize a stack to store indices of bars.
2. Iterate through each bar:
    - If the current bar is **shorter or equal** → push its index.
    - If the current bar is **taller** → pop the stack until this is no longer true.
3. For each popped bar:
    - The **left boundary** = new top of the stack
    - The **right boundary** = current bar
    - The **width** = `right - left - 1`
    - The **height** = `min(height[left], height[right]) - height[bottom]`
4. Multiply `width × height` → add to total trapped water 💧

### 🧱 Example
```
Height: [0,1,0,2,1,0,1,3,2,1,2,1]

Step: index 2
Left boundary = 1
Right boundary = 3
Bottom = 0
Width = 1
Height = min(1,3) - 0 = 1
Water trapped = 1 * 1 = 1
```

### ⏱️ Complexity Analysis
- **Time Complexity:** `O(n)` — each bar is pushed/popped at most once
- **Space Complexity:** `O(n)` — stack stores indices of bars

### 🔥 Why This Approach Rocks
- ✅ Handles tricky elevation patterns efficiently
- ✅ Single pass through the array
- ✅ Space-efficient and intuitive for visualization
- ✅ Great for interviews and competitive programming

---