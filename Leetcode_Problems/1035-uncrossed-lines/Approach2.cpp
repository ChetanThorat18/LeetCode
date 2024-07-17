class Solution {
public:
    int m; // size of nums1
    int n; // size of nums2

    vector<vector<int>>dp;

    int solve(vector<int>& nums1, vector<int>& nums2, int i, int j){
        // Base case: If we have reached the end of either array, return 0
        if(i >= m || j >= n)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        // If the current elements of nums1 and nums2 are equal
        if(nums1[i] == nums2[j])
            // Include this pair and recursively find the next pair
            return dp[i][j] = 1 + solve(nums1, nums2, i+1, j+1);

        // If the current elements are not equal, explore two options:
        // 1. Fix i and move j forward
        int fix_i = solve(nums1, nums2, i, j+1);
        // 2.  Fix j and move i forward
        int fix_j = solve(nums1, nums2, i+1, j);

        // Return the maximum of the two options above
        return dp[i][j] = max(fix_i, fix_j);
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        // Approach : Recursion + Memoization
        m = nums1.size(); 
        n = nums2.size(); 

        dp.assign(m, vector<int>(n, -1));

        // Call the recursive function starting from index 0 of both arrays
        return solve(nums1, nums2, 0, 0);
    }
};
