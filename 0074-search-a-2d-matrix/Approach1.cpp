class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // First Approach

        int m = matrix.size();  // No. of rows
        int n = matrix[0].size(); // No. of  columns

        int i=0,j=n-1;  // Start from the top-right corner of the matrix

        while(i < m && j >=0){
            // If current element is greater than target , it means target is towards left ,so move left in the same row
           if( matrix[i][j] > target ){
               j--;
           }
            // If current element is less than target , it means target is towards right , so move down to the next row
           else if( matrix[i][j] < target ){
               i++;
           } 
           else{
               // target found
               return true;
           }
        }

        return false;

      /* (i < m && j >=0) ==> since we are incrementing i we check if it less than no. of rows and since we are decrementing j we check if it >=0 */


    }
};
