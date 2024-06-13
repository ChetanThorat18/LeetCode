class Solution {
public:
    
    int solve(vector<int>& nums , int i, int n,vector<int>&memo){
        // Base case: if we're beyond the last house, return 0
        if(i >= n)
            return 0;


        // Check if the solution for the current subproblem is already computed
        if (memo[i] != -1)
            return memo[i];

        // At current house , we have two choice , either steal money from house or skip the house

        // 1. Steal from the current house and recursively solve for the next available house after skipping the next one
        int steal = nums[i] + solve(nums,i+2,n,memo);

        // 2.Skip the current house and move to the next house
        int skip = solve(nums,i+1,n,memo);

        // Store the result of the current subproblem in the memoization table
        memo[i] = max(steal, skip);

        // Return the maximum of stealing from the current house or skipping it
        return memo[i];
    }

    int rob(vector<int>& nums) {
        // Approach2 : Recursion + Memoization
        int n = nums.size();

        // Initialize memoization vector with -1 indicating not computed
        vector<int> memo(n, -1); 

        // Start the recursion from the first house
        return solve(nums,0,n,memo);
    }
};
