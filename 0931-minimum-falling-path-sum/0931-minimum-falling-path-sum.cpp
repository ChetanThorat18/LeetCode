class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // Approach: Bottom-Up DP (Tabulation)
        
        int n = matrix.size(); 
        
        vector<vector<int>> dp(n, vector<int>(n)); // Initialize a 2D vector for DP
        // State : dp[row][col] ==> Minimum Falling Path Sum to reach till cell [row][col]
        
        // Base case: Assign the values of the first row to the DP table
        for(int col = 0; col < n; col++) {
            dp[0][col] = matrix[0][col];
        }

        // Iterate over each row starting from the second row
        for(int row = 1; row < n; row++) {
            for(int col = 0; col < n; col++) {
                int path1 = INT_MAX, path2 = INT_MAX, path3 = INT_MAX;

                // Check if there's a valid column to the left
                if(col - 1 >= 0)
                    // Calculate the falling path sum going diagonally down to right
                    path1 = matrix[row][col] + dp[row - 1][col - 1];

                // Calculate the falling path sum going straight down
                path2 = matrix[row][col] + dp[row - 1][col];

                // Check if there's a valid column to the right
                if(col + 1 < n)
                    // Calculate the falling path sum going diagonnaly down to left
                    path3 = matrix[row][col] + dp[row - 1][col + 1];

                // Choose the minimum of the three possible paths
                dp[row][col] = min({path1, path2, path3});
            }
        }

        int result = INT_MAX;
        // Find the minimum falling path sum in the last row
        for(int col = 0; col < n; col++) {
            result = min(result, dp[n - 1][col]);
        }

        return result; // Return the minimum falling path sum
    }
};