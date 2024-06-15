class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();      // Number of rows in the matrix
        int n = matrix[0].size();   // Number of columns in the matrix
        int maxSide = 0;            // Variable to store the maximum side length of the square of '1's found

        // Create a DP table initialized with 0
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // The dp[i][j] represents the side length of the largest square whose bottom-right corner is at the cell (i, j)

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // If the current cell contains '1'
                if (matrix[i][j] == '1') {
                    // If it's in the first row or first column, the largest square ending here is 1
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        // Otherwise, the size of the square ending at (i, j) is determined by the minimum
                        // of the sizes of squares ending at its left, top, and top-left neighbors + 1
                        dp[i][j] = 1 + min({ dp[i][j-1], dp[i-1][j], dp[i-1][j-1] });
                    }
                }

                // Update maxSide with the maximum value found in the dp table
                maxSide = max(maxSide, dp[i][j]);
            }
        }

        // Return the area of the largest square found
        return maxSide * maxSide;
    }
};
