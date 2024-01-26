class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
             int m = matrix.size();      // Number of rows
        int n = matrix[0].size();   // Number of columns

        int start = 0;              // Start index of the 1D representation of the matrix
        int end = m * n - 1;        // End index of the 1D representation of the matrix

        while (start <= end) {
            int mid = start + (end - start) / 2;

            // Convert 1D mid to 2D row and column indices
            int row = mid / n;      // Divide mid by number of columns to get the row index
            int column = mid % n;   // Use modulo to get the column index

            // Compare the matrix element at (row, column) with the target
            if (matrix[row][column] > target) {
                // If the current element is greater than the target, update 'end' to search in the left half
                end = mid - 1;
            } else if (matrix[row][column] < target) {
                // If the current element is less than the target, update 'start' to search in the right half
                start = mid + 1;
            } else {
                // If the current element is equal to the target, the target is found
                return true;
            }
        }

        return false;
    }
};