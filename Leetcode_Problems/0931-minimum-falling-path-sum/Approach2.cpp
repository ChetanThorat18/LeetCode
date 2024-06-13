class Solution {
public:
    int n; 
    vector<vector<int>>dp;

    int solve(vector<vector<int>>& matrix, int row, int col){
        // Base case: if we reach the last row, return the value at the current position
        if(row == n-1)
            return matrix[row][col];

        if(dp[row][col] != -1)
            return dp[row][col];

        int minPathSum = INT_MAX;

        // Check if there's a valid column to the left
        if(col-1 >= 0)
            // Recursively find the minimum falling path sum going diagonally left
            minPathSum = min(minPathSum ,  matrix[row][col] + solve(matrix,row+1,col-1));
        
        // Recursively find the minimum falling path sum going straight down
        minPathSum = min(minPathSum , matrix[row][col] + solve(matrix,row+1,col));

        // Check if there's a valid column to the right
        if(col+1 < n)
            // Recursively find the minimum falling path sum going diagonally right
            minPathSum = min(minPathSum , matrix[row][col] + solve(matrix,row+1,col+1));

        // Return the minimum falling path sum from the current position
        return dp[row][col] =minPathSum;
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        // Approach : Recursion + Memoization
        n = matrix.size(); 

        int result = INT_MAX; 

        dp.assign(n , vector<int>(n, -1));
        int row = 0; // Start from the first row
        for(int col=0; col<n; col++){
            // For each column in the first row, find the minimum falling path sum
            result = min(result , solve(matrix, row , col));
        }

        // Return the minimum falling path sum for the entire matrix
        return result;
    }
};
