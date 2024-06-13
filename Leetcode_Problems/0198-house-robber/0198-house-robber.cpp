class Solution {
public:
    int rob(vector<int>& nums) {
        // Approach: Bottom-up Dynamic Programming
        
        int n = nums.size(); 
        // Create a memoization array to store the maximum amount of money that can be robbed from the first i houses
        vector<int> memo(n + 1, 0); 
        
        // Base cases:
        // If there are no houses, the maximum amount of money that can be robbed is 0
        memo[0] = 0; 
        // If there is only one house, the maximum amount of money that can be robbed is the money in that house
        memo[1] = nums[0];
         

        for(int i = 2; i <= n; i++) {
            // Calculate the maximum amount of money that can be robbed if the current house is robbed
            int steal = nums[i - 1] + memo[i - 2]; // nums[i - 1] represents the money in the current house
            
            // Calculate the maximum amount of money that can be robbed if the current house is skipped
            int skip = memo[i - 1]; // If the current house is skipped, the maximum amount of money is the same as the maximum amount of money from the previous house
            
            // Store the maximum of the two options (rob or skip) in the memoization array
            memo[i] = max(steal, skip);
        }

        // The maximum amount of money that can be robbed from all houses is stored in the last element of the memoization array
        return memo[n];
    }
};
