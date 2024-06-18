class Solution {
public:
    int uniquePaths(int m, int n) {
        // Approach : Bottom-Up DP (Tabulation)

        // Create a 2D vector 'dp' of size m x n, initialized with zeros
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // State : DP[row][col] ==> represents the number of unique paths to reach the cell located at (row, col) from the top-left corner (0, 0)
        
        // Initialize the leftmost column of dp matrix
        for(int row = 0; row < m; row++){
            dp[row][0] = 1;  // There is only one way to reach any cell in the leftmost column (moving straight down)
        }

        for(int row = 0; row < m; row++){
            for(int col = 1; col < n; col++){

                // Calculate number of paths to reach dp[row][col] by summing paths from left and above cells
                int left = dp[row][col - 1];  // Number of paths from the cell to the left
                int up = 0;  
                
                if(row > 0){
                    up = dp[row - 1][col];  // Number of paths from the cell above
                }
                
                dp[row][col] = left + up;  // Total paths to reach dp[row][col]
            }
        }

        // Return the number of unique paths to reach the bottom-right corner (dp[m-1][n-1])
        return dp[m - 1][n - 1];
    }
};