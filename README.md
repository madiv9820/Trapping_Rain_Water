# [🌧️💧 Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/description/?envType=study-plan-v2&envId=top-interview-150)
Imagine a line of bars, each with a certain **height** 🏔️, represented by an array of non-negative integers. Each bar is **1 unit wide**.

When it rains, water 💦 collects in the valleys between the bars. Your mission?

**Figure out how much water can be trapped** after the rain 🌧️, given the heights of the bars.

Think of it like:
- Mountains ⛰️ and valleys ⛏️
- Water puddles forming in the dips 💧
- Your task: **count all the water trapped** without spilling over the edges! 🏞️

### 🌧️ Example 1
- **Input:** `height = [0,1,0,2,1,0,1,3,2,1,2,1]` <br>
![](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)
- **Output:** `6` 💦
- **Explanation:** The elevation map looks like a mix of **peaks and valleys** ⛰️⬇️.
    - The black bars represent the **heights of the terrain** 🏔️
    - The blue sections show the **water trapped after the rain** 💧 
    
    In total, **6 units of rainwater** are trapped. 🌊

### 🌧️ Example 2
- **Input:** `height = [4,2,0,3,2,5]`
- **Output:** `9` 💦
- **Explanation:**
    - Tall bars create deep valleys ⛰️⬇️
    - Water collects in the dips, forming **9 units of trapped water** 💧

    Even mountains need a raincoat sometimes! 😎🌧️

### ⚡ Constraints
- `n == height.length` 📏 — Number of bars in the elevation map
- `1 <= n <= 20,000` 🏔️ — From a tiny hill ⛰️ to a huge mountain range 🏔️
- `0 <= height[i] <= 100,000` ⬆️ — Height of each bar (no negative terrain!)
- 💦 Rainwater can only collect in dips between the bars, so know your limits! 🌊🌧️

## Approaches 🧠

| **Approach Name**             | **Short Explanation**                                                                                                                                                               |
| ------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 🐢 [**Brute Force**](https://github.com/madiv9820/Trapping_Rain_Water/tree/Approach_01-Brute_Force)        | For each bar, look left 🔙 and right 🔜 to find the tallest bars, then water is limited by the smaller one 💧. Simple but slow.                                                 |
| 📦 [**Prefix–Suffix (DP)**](https://github.com/madiv9820/Trapping_Rain_Water/tree/Approach_02-Prefix_Suffix_Arrays) | Precompute `leftMax` ⬅️ and `rightMax` ➡️ arrays for all bars, then calculate trapped water in one pass 💧. Faster than brute force.                                            |
| ↔️ [**Two Pointers**](https://github.com/madiv9820/Trapping_Rain_Water/tree/Approach_03-Two_Pointers)       | Use two pointers from both ends ⬅️➡️, always move the shorter side, and track running `leftMax`/`rightMax` 🧱 to accumulate water efficiently 💦.                               |
| 📚 [**Monotonic Stack**](https://github.com/madiv9820/Trapping_Rain_Water/tree/Approach_04-Monotonic_Stack)    | Maintain a decreasing stack of bar indices 📊. When a taller bar appears, pop valleys and calculate trapped water between boundaries 🏞️. Useful for tricky elevation patterns. |
---