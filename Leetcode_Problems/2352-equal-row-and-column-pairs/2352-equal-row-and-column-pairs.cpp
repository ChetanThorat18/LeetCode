class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
       // Optimal Approach using map
        int n = grid.size();
        int count = 0; 
        map<vector<int>,int>mp;

        // Store each row(key) and it's occurence(value) in map
        for(int row=0; row<n; row++){
            mp[grid[row]]++;
        }

        // Extract elements from the current column and check if it already present in map
        for(int col=0; col<n; col++){
            vector<int>temp;
            for(int row=0; row<n; row++){
                temp.push_back(grid[row][col]);
            }

            count += mp[temp];
        }

        return count;
    }
};