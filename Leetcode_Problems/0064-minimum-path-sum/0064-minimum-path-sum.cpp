
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // Approach : Bottom-Up DP (Tabulation)

        int m = grid.size(); // Number of rows
        int n = grid[0].size(); // Number of columns

        vector<vector<int>> dp(m, vector<int>(n)); // 2D vector to store minimum path sums

        // State: dp[i][j] represents the minimum path sum to reach cell grid[i][j]

        dp[0][0] = grid[0][0];

        // Initialize the first row of the dp table
        // For first row cell we can only reach from left direction
        for(int col = 1; col < n; col++) {
            grid[0][col] = grid[0][col] + grid[0][col - 1];
        }

        // Initialize the first column of the dp table
        // For first column cell we can only reach from up direction
        for(int row = 1; row < m; row++) {
            grid[row][0] = grid[row][0] + grid[row - 1][0];
        }

        // Iterate through the grid to fill the dp table
        for(int row = 1; row < m; row++) {
            for(int col = 1; col < n; col++) {
                // Calculate the minimum path sum by choosing the minimum of the sum of the cell to the left and the cell above
                int left = grid[row][col - 1];
                int up = grid[row - 1][col];
                grid[row][col] = grid[row][col] + min(left, up);
            }
        }

        // Return the minimum path sum to reach the bottom-right cell
        return grid[m - 1][n - 1];
    }
};