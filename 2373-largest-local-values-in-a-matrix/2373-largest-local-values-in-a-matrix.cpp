class Solution {
public:
    // Function to find the maximum value in a 3x3 submatrix centered at (row, col)
    int findLocalMaximum(vector<vector<int>>& grid, int row, int col) {
        int maxVal = INT_MIN; 
        
        // Loop through the 3x3 submatrix centered at (row, col)
        for(int i = row; i <= row + 2; i++) {
            for(int j = col; j <= col + 2; j++) {
                maxVal = max(maxVal, grid[i][j]); 
            }
        }

        return maxVal; // Return the maximum value found in the submatrix
    }

    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> maxLocal(n - 2, vector<int>(n - 2)); // Initialize the result matrix of size(n-2 x n-2)
        
        // Loop through the input matrix to find the largest value in every contiguous 3x3 submatrix
        for(int row = 0; row < n - 2; row++) {
            for(int col = 0; col < n - 2; col++) {
                maxLocal[row][col] = findLocalMaximum(grid, row, col); // Store the maximum value in the result matrix
            }
        }

        return maxLocal; 
    }
};