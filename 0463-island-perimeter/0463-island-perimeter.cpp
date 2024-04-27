class Solution {
public:
    int m; // Number of rows in the grid
    int n; // Number of columns in the grid
    int perimeter; // Perimeter of the island

    // Depth-first search to explore the island and calculate its perimeter
    void dfs(vector<vector<int>>& grid , int i, int j){

        // Base case: If the cell is out of bounds or is water, increment perimeter and return
        if(i < 0 || i >= m || j < 0 || j>= n || grid[i][j] == 0){
            perimeter++;
            return;
        }

        // If the cell has already been visited, return
        if(grid[i][j] == -1)
            return;

        // Mark the cell as visited
        grid[i][j] = -1;

        // Explore adjacent cells in all four directions
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size(); 
        n = grid[0].size(); 
        perimeter = 0; 

        // Traverse the grid to find the starting cell of the island
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                // If the cell is land, start DFS from here and return perimeter
                if(grid[i][j] == 1){
                    dfs(grid, i, j);
                    return perimeter;
                }
            }
        }

        return -1; 
    }
};
