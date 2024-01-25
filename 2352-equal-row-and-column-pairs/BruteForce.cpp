class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        // Brute Force : For each row check every column O(n^3)
        int n = grid.size();
        int count = 0;

        // Fix the row
        for(int row=0; row<n; row++){
            // Fix the column
            for(int col = 0; col<n; col++){
                bool isEqual = true;
                // Check each element in the row and corresponding column
                for(int k=0; k<n; k++){
                    if( grid[row][k] != grid[k][col]){
                        isEqual = false;
                        break;
                    }
                }
                // If the row and column are equal, increment the count
                if(isEqual){
                    count++;
                }
            }
        }

        return count;


    }
};
