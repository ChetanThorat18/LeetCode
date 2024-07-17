class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(); 
        int n = nums2.size(); 

        // Create a 2D DP table with dimensions (m+1) x (n+1)
        // State : dp[i][j] ==> Maximum No of uncrossed-lines of nums1 of length i and nums2 of length j
        vector<vector<int>> dp(m+1, vector<int>(n+1));

        // Initialize the DP table
        // Base case: When either nums1 or nums2 is empty, max uncrossed lines is 0
        for(int col = 0; col <= n; col++) {
            dp[0][col] = 0;
        }
        for(int row = 0; row <= m; row++) {
            dp[row][0] = 0;
        }

        // Fill the DP table
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                // If nums1[i-1] and nums2[j-1] are equal, they can form an uncrossed line
                if(nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1]; // Include this pair and add to the count
                } else {
                    // If they are not equal, take the maximum value from either excluding nums1[i-1] or nums2[j-1]
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        return dp[m][n];
    }
};