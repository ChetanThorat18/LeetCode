class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();  // No. of Rows
        int n = m ; // No. of Columns (square matrix)

/*
    Approach :
    Step 1 => Take Transpose of matrix (i.e swap matrix[i][j] with matrix[j][i])
    Step 2 => Reverse each row

    Eg- [
            STEP 1 : 

            [1,2,3]             [1,4,7]
            [4,5,6]       ==>   [2,5,8]
            [7,8,9]             [3,6,9]

            STEP 2 :

            [1,4,7]             [7,4,1]
            [2,5,8]       ==>   [8,5,2]
            [3,6,9]             [9,6,3]

        ]
*/
        for(int i=0; i<m; i++){
            for(int j=i; j<n; j++){
                if( i == j)
                    continue;
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i=0;i<m;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
       
    }
};