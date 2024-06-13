class Solution {
public:
    int solve(vector<int>& nums , int i, int n){
        // Base case: if we're beyond the last house, return 0
        if(i >= n)
            return 0;

        // At current house , we have two choice , either steal money from house or skip the house

        // 1. Steal from the current house and recursively solve for the next available house after skipping the next one
        int steal = nums[i] + solve(nums,i+2,n);

        // 2.Skip the current house and move to the next house
        int skip = solve(nums,i+1,n);

        // Return the maximum of stealing from the current house or skipping it
        return max(steal , skip);
    }

    int rob(vector<int>& nums) {
        // Approach1 : Recursion
        int n = nums.size();

        // Start the recursion from the first house
        return solve(nums,0,n);
    }
};
