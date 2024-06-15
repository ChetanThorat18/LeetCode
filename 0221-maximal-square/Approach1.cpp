class Solution {
public:
    int m;         // Number of rows in the matrix
    int n;         // Number of columns in the matrix
    int maxSide;   // Maximum side length of the square found so far

    int solve(vector<vector<char>>& matrix, int i, int j) {

        // Base case: If we are out of bounds, return 0
        if (i >= m || j >= n) {
            return 0;
        }

        // Recursive calls to get the sizes of squares  at right, bottom, and bottom-right cells
        int right = solve(matrix, i, j + 1);
        int bottom = solve(matrix, i + 1, j);
        int diagonal = solve(matrix, i + 1, j + 1);

        // If the current cell is '1', calculate the side length of the square starting at (i, j)
        if (matrix[i][j] == '1') {
            // The side length of the square ending at (i, j) is 1 plus the minimum of the side lengths of squares
            // ending at the right, bottom, and bottom-right cells
            int side = 1 + min({right, bottom, diagonal});
            
            // Update the maximum side length found so far
            maxSide = max(maxSide, side);
            
            // Return the side length of the square ending at (i, j)
            return side;
        } else {
            // If the current cell is '0', it can't be part of a square of '1's, so return 0
            return 0;
        }
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        // Approach : Recursion 

        // Initialize the dimensions of the matrix
        m = matrix.size();
        n = matrix[0].size();

        maxSide = 0; // Initialize maxSide to 0

        // Start the recursion from the top-left corner of the matrix
        solve(matrix, 0, 0);

        // Calculate and return the area of the largest square found
        return maxSide * maxSide;
    }
};
