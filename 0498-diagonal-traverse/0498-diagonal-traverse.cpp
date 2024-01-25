class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();    // No. of rows
        int n = mat[0].size(); // No. of columns

        // Using an unordered_map to store values of each diagonal
        map<int, vector<int>> mp;
        vector<int> result;

        // All cells in the same diagonal (i,j) have the same addition so we
        // can get the diagonal of a cell using the addition i+j.
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[i + j].push_back(mat[i][j]);
            }
        }

        for (auto& itr : mp) {
            //  reverse the of vectors for even-indexed diagonals in order to
            //  get correct zigzag pattern.
            if ((itr.first) % 2 == 0) {
                reverse(itr.second.begin(), itr.second.end());
            }

            for (auto num : itr.second) {
                result.push_back(num);
            }
        }

        return result;
    }
};

/* https://youtu.be/7HAKiGZSrWc?si=NkdtNmtmjxIgX7Zz */