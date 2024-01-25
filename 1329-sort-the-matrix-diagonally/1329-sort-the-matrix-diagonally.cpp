class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int m = mat.size();  // No. of Rows
        int n = mat[0].size(); // no. of Columns

        // Using an unordered_map to store values of each diagonal
        unordered_map<int,vector<int>>mp;

       // All cells in the same diagonal (i,j) have the same difference so we can get the diagonal of a cell using the difference i-j.
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mp[i-j].push_back(mat[i][j]);
            }
        }

        // Sort each vector in the unordered_map
        for(auto &it :mp){
            sort(it.second.begin(),it.second.end());
        }


        // Put the sorted values back into the matrix
        // Putting values from back, to avoid shifting overhead in vector(if we put from front , it will cause shifting overhead)
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                mat[i][j] = mp[i-j].back();   // get last value in vector
                mp[i-j].pop_back();           // remove last value in vector
            }

        }

        return mat;
    }
};

/* https://youtu.be/mNWwJQ7_z4Q?si=RpdJqNvoV_IQuxbF  */