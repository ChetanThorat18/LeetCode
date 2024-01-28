class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
       // Brute Force 
       int m = matrix.size();
       int n = matrix[0].size();

       // Use sets to store the rows and columns that need to be set to zero
       set<int>rowsToZero;
       set<int>colsToZero;

        // Iterate through the matrix to find zeros and mark corresponding rows and columns
       for(int row=0; row < m; row++){
           for(int col=0; col<n; col++){

               if(matrix[row][col] == 0){
                   rowsToZero.insert(row);
                   colsToZero.insert(col);
               }
           }
       }  

       // Set all the marked rows to zero
       for(int row : rowsToZero){
           for(int j=0; j<n; j++){
               matrix[row][j] = 0;
           }
       }

       // Set all the marked columns to zero
       for(int col : colsToZero){
           for(int j=0; j<m; j++){
               matrix[j][col] = 0;
           }
       }

       
    }
};
