class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Bottom-Up DP approach
        
        int n = nums.size(); 
        
        vector<int> dp(n, 0);
        // State :: dp[i] ==> maximum possible Subarray sum ending at index i
        
        dp[0] = nums[0]; // Base case: The maximum subarray sum ending at index 0 is nums[0]
        
        int result = dp[0]; // Initialize the result to be the maximum subarray sum found so far
        
        for(int i = 1; i < n; i++) {
            // The maximum subarray sum ending at index i can be either nums[i] itself or
            // the maximum subarray sum ending at index i-1 plus nums[i]
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            
            // Update the overall result to be the maximum of the current result and dp[i]
            result = max(result, dp[i]);
        }

        return result; // Return the maximum subarray sum found
    }
};