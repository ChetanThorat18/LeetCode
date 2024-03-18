class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();  
        int n = mat[0].size();  
        vector<int> result; 

        int row = 0, col = 0;  
        bool up = true;  // Flag to track the direction of traversal (upward or downward)
        
        while (row < m && col < n) {
            // Add the current element to the result vector
            result.push_back(mat[row][col]);
            
            // Move to the next element based on the direction of traversal

            // If traversing upwards
            if (up) {  

                // Check if it's possible to move diagonally upwards
                if (row > 0 && col < n - 1) {
                    row--;  // Move upwards
                    col++;  // Move to the next column
                }

                // If not possible to move diagonnally upward
                else {
                    // Change direction to downwards
                    up = false; 

                    // Check if it's possible to move to the right
                    if (col < n - 1) {
                        col++;  // Move to the next column
                    } else {
                        row++;  // Move downwards
                    }
                }
            }

            // If traversing downwards
            else {  
                // Check if it's possible to move diagonally downwards
                if (col > 0 && row < m - 1) {
                    row++;  // Move downwards
                    col--;  // Move to the previous column
                } else {
                    up = true;  // Change direction to upwards

                    // Check if it's possible to move downwards
                    if (row < m - 1) {
                        row++;  // Move downwards
                    } else {
                        col++;  // Move to the next column
                    }
                }
            }
        }
        
        return result;  
    }
};
