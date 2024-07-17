class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // Approach: Bottom-Up Dynamic Programming (DP)

        int n = nums.size();

        // Define the DP array where dp[i] represents the length of the longest
        // increasing subsequence that ends with the element at index i.
        vector<int> dp(n, 1);

        // Variable to keep track of the maximum length of the LIS found so far.
        int maxLIS = 1;  // Single element is also a subsequence

        // Iterate through the array to fill the DP table.
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                // If the current element nums[i] is greater than nums[j],
                // it means we can extend the increasing subsequence ending at j.
                if(nums[j] < nums[i]) {
                    // Update dp[i] to be the maximum of its current value and dp[j] + 1.
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            // Update the maxLIS with the maximum value in the dp array so far.
            maxLIS = max(maxLIS, dp[i]);
        }

        return maxLIS;
    }
};
