#ifndef SOLUTION_H
#define SOLUTION_H

// Helpful macros to get minimum and maximum values 🔧
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int trap(int* height, int heightSize) {
    // This will store the total amount of trapped rainwater 🌊
    int waterTrapped = 0;

    // Iteration helpers
    int currentPosition;
    int prevPostition;
    int nextPosition;

    // These will track the tallest bars on the left and right 🧱
    int leftMax; 
    int rightMax;
    
    // We skip the first and last bars since water cannot be trapped there 🚫
    for (currentPosition = 1; currentPosition < heightSize - 1; ++currentPosition) {

        // Reset max values for this position
        leftMax = -1;
        rightMax = -1;

        // 🔍 Find the tallest bar to the LEFT of currentPosition
        for (prevPostition = currentPosition - 1; prevPostition >= 0; --prevPostition)
            leftMax = MAX(leftMax, height[prevPostition]);
        
        // 🔎 Find the tallest bar to the RIGHT of currentPosition
        for (nextPosition = currentPosition + 1; nextPosition < heightSize; ++nextPosition)
            rightMax = MAX(rightMax, height[nextPosition]);

        // 💧 Water trapped at this position is determined by:
        // min(leftMax, rightMax) - current height
        // If negative, we add 0 (no water trapped)
        waterTrapped += MAX(0, (MIN(leftMax, rightMax) - height[currentPosition]));
    }
    
    // 🎉 Return total accumulated trapped water
    return waterTrapped;
}

#endif