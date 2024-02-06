class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       // Initialize a 2D vector to store Pascal's triangle
       vector<vector<int>>result(numRows);

       for(int i=0; i<numRows; i++){
           // Each row 'i' will have 'i+1' columns
           result[i] = vector<int>(i+1,1);

            // First and Last element of each row is always 1
            // So, Iterate through the second to second-last columns in the current row
           for(int j=1; j<i; j++){
               // Calculate each element based on the sum of the two elements above it
               result[i][j] = result[i-1][j] + result[i-1][j-1];
           }
       } 

       return result;
    }
};

/*

 Each element in Pascal's triangle is the sum of the two elements directly above it:
    result[i][j] = result[i-1][j] + result[i-1][j-1];

    Example:
    3rd Row:           1     2     1
    Calculation for 4th Row:
    4th Row:           1     3     3     1
                           (2+1) (2+1)
    The value '3' is calculated as: value at the same column in the previous row + value at the previous row and previous column
    3 => 2 + 1 
    
*/
