class Solution {
public:
    int rows;
    int cols; 
    vector<vector<int>>dp;

    int solve(vector<vector<int>>& grid, int i, int j){
        // If reached the bottom-right cell, return its value
        if(i == rows-1 && j == cols-1)
            return grid[i][j];

        if(dp[i][j] != -1)
            return dp[i][j];

        // If reached the bottom row, can only move right
        if(i == rows-1){
            return dp[i][j] = grid[i][j] + solve(grid, i, j+1);
        }
        // If reached the rightmost column, can only move down
        else if(j == cols-1){
            return dp[i][j] = grid[i][j] + solve(grid, i+1, j);
        }
        // Otherwise, calculate the minimum path sum by considering both right and down movements
        else{
            int right = grid[i][j] + solve(grid, i, j+1);
            int down =  grid[i][j] + solve(grid, i+1, j);

            // Choose the minimum path sum between moving right and moving down
            return dp[i][j] = min(right , down);
        }
    }

    int minPathSum(vector<vector<int>>& grid) {
        // Approach : Recursion + Memoization
        rows = grid.size();
        cols = grid[0].size();

        dp.assign(rows,vector<int>(cols,-1));

        // Start recursion from the top-left cell
        return solve(grid,0,0);
    }
};
