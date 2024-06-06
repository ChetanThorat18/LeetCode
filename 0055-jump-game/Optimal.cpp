class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        // Initialize the maximum reachable index from the current position
        int maxReachable = 0;

        for (int i = 0; i < n; i++) {
            // If the current index is beyond the maximum reachable index,
            // it means we cannot reach this index from any previous index
            if (i > maxReachable)
                return false;

            // Calculate the maximum reachable index from the current position
            int currMaxReach = i + nums[i];

            // Update the maximum reachable index if necessary
            maxReachable = max(maxReachable, currMaxReach);
        }

        // If we can reach the end of the array, return true
        return true; 
    }
};
