class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(); 
        int columns = matrix[0].size(); 

        // Ignore first row and first column because they don't have previous diagonal element to check 
        for(int i = 1; i < rows; i++) {
            for(int j = 1; j < columns; j++) {
                // Check if the current cell value is equal to the value of the cell diagonally above and to the left
                // If not equal, it means the matrix is not Toeplitz, so return false
                if(matrix[i][j] != matrix[i - 1][j - 1]) {
                    return false;
                }
            }
        } 

        // If all cells satisfy the Toeplitz condition, return true
        return true;
    }
};
