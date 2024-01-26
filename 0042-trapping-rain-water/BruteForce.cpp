class Solution {
public:
    int trap(vector<int>& height) {
        int water = 0;
        
        // Exclude first and last block because we can't store water on them
        for(int i = 1; i < height.size() - 1; i++) {

            int leftmax = height[i];
            
            // Iterate to find the maximum height to the left of the current block
            for(int j = 0; j < i; j++) {
                leftmax = max(leftmax, height[j]);
            }

            int rightmax = height[i];

            // Iterate to find the maximum height to the right of the current block
            for(int j = i + 1; j < height.size(); j++) {
                rightmax = max(rightmax, height[j]);
            }

            // Calculate the trapped water for the current block and add it to the total water
            water = water + (min(leftmax, rightmax) - height[i]);
        }
        
        return water;
    }
};
