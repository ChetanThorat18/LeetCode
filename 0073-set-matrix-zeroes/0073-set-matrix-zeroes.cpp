class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       // Efficient : O(1) Space => Using first Row and first Column of original matrix to determine which row and column need to be set to zero

       int m = matrix.size();
       int n = matrix[0].size();

        // One extra variable needed because (0,0) position gets overlaped
        bool zeroFirstRow = false;

        // STEP 1
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {

                if (matrix[row][col] == 0) {
                    // Use the first row and first column to store information about zeros

                    matrix[0][col] = 0;

                    if(row == 0)
                        zeroFirstRow = true;
                    else
                        matrix[row][0] = 0;
                }
            }
        }

        // STEP 2 

        /*
            Note: We skip the first row and first column during this iteration because they were used
            to store information about which rows and columns need to be zeroed.

            The reason is that during the iteration through the rest of the matrix, we rely on the information stored in the first row and column to determine whether a particular element needs to be zeroed. If we zero the first row and column too early, we might lose that information, leading to incorrect results. Elements that should not be zeroed might get zeroed, and the final matrix won't accurately represent the locations of zeros.
 
        */

        // Iterate through the matrix and set zeros based on information stored in the first row and first column
        for (int row = 1; row < m; ++row) {
            for (int col = 1; col < n; ++col) {
                // Check information stored in first row and column  
                if( matrix[0][col] == 0  || matrix[row][0] == 0)
                    // Set the element to zero if the information indicates it
                    matrix[row][col] = 0;
            }
        }


        // STEP 3
        // Update Remaining First Row and First Column 

         if(matrix[0][0] == 0){
            // Set First column to zero
            for(int j=0; j<m; j++){
                matrix[j][0] = 0;
            }
        }
          
        if( zeroFirstRow == true ){
            // Set first row to zero
            for(int j=0; j<n; j++){
                matrix[0][j] = 0;
            }
        }

       
       

       
    }
};


/*
   If we change the sequence of the operations in STEP 3, it might result in incorrect zeroing. For example, if we zero the first column before checking whether the first row needs to be zeroed, you might lose information about the first row, leading to incorrect results.

*/