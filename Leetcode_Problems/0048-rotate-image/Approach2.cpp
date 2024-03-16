class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Get the size of the matrix 

        // i sstart from outer layer and goes till inner layer
        for(int i = 0; i < (n + 1) / 2; i++) {
            // j select elements in current layer
            for(int j = 0; j < n / 2; j++) {
                // Store the top-left element temporarily
                int temp = matrix[i][j];

                // Move bottom-left element to top-left
                matrix[i][j] = matrix[n - 1 - j][i];

                // Move bottom-right element to bottom-left
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];

                // Move top-right element to bottom-right
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];

                // Move top-left (stored in temp) to top-right
                matrix[j][n - 1 - i] = temp;
            }
        }
    }
};
