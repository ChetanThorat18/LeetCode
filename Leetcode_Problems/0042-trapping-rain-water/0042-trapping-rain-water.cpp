class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        // Calculate the leftMax array starting from the left
        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(height[i], leftMax[i - 1]);
        }

        // Calculate the rightMax array starting from the right
        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(height[i], rightMax[i + 1]);
        }

        int trappedWater = 0;

        // Iterate through each bar (excluding the first and last)
        for (int i = 1; i < n - 1; i++) {
            // Calculate the minimum height of leftMax and rightMax
            int minHeight = min(leftMax[i], rightMax[i]);
            // Calculate the trapped water at the current position
            trappedWater = trappedWater + max(0, minHeight - height[i]);
        }

        return trappedWater;
    }
};

/*
    Two arrays (leftMax and rightMax) are initialized to store the maximum height to the left and right of each bar.

The leftMax array is calculated by iterating through the bars from left to right and storing the maximum height encountered so far.

The rightMax array is calculated by iterating through the bars from right to left and storing the maximum height encountered so far.

The main loop iterates through each bar (excluding the first and last) and calculates the trapped water at that position.

The trapped water at each position is calculated by finding the minimum height of the leftMax and rightMax for the current bar and subtracting the bar's height.

The result is the sum of trapped water at each position, providing the total trapped water in the histogram.
*/