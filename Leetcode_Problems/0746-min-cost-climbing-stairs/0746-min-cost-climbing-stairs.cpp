class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Approach : Bottom Up DP
        
        int n = cost.size();
        
        // Create a DP array where dp[i] will store the minimum cost to reach i^th step 
        vector<int> dp(n);
        
        // Base cases
        dp[0] = cost[0];  // Cost to reach step 0 is the cost of step 0 itself
        dp[1] = cost[1];  // Cost to reach step 1 is the cost of step 1 itself
        
        // Build the DP array from step 2 to n-1
        for (int i = 2; i < n; ++i) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        
        // The minimum cost to reach the top is the minimum of reaching the last two steps
        return min(dp[n-1], dp[n-2]);
    }
};