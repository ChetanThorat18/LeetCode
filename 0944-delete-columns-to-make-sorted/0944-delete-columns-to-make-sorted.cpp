class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(); // Number of strings
        int m = strs[0].size(); // Length of each string
        int deletedColumns = 0; // Counter for deleted columns

        // Iterate through each column
        for (int j = 0; j < m; ++j) {
            // Check if the column is sorted lexicographically
            for (int i = 1; i < n; ++i) {
                // If the current string is smaller than the previous one in the column, it's not sorted
                if (strs[i][j] < strs[i - 1][j]) {
                    ++deletedColumns; // Increment the count of deleted columns
                    break; // No need to check further in this column
                }
            }
        }

        return deletedColumns;
    }
};