class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Approach: Bottom-Up Dynamic Programming (Tabulation)
        // Initialize the size of the input array
        int n = nums.size();

        // Create a DP table to store whether it's possible to reach each index
        vector<bool> dp(n , false);
        // dp[i] represents whether we can reach index i or not

        // Base case: It's always possible to reach the first index
        dp[0] = true;

        // Iterate over each index from 1 to n - 1
        for (int i = 1; i < n; i++) {
            // Check all indices before i to see if it's possible to reach i
            for (int j = i - 1; j >= 0; j--) {

                // If it's possible to reach index j and from j we can jump to i or beyond i
                if ( (dp[j] == true)  &&  (j + nums[j] >= i) ) {
                    // Mark that it's possible to reach index i
                    dp[i] = true;
                    // Once we find a reachable index j, break the inner loop
                    break;
                }   
            }

        }

        // Return whether it's possible to reach the last index
        return dp[n - 1];
    }
};