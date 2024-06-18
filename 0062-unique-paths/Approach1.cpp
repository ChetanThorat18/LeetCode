class Solution {
public:
    int solve(int row, int col, int m, int n){
        // Base case: If the current position is out of bounds, return 0
        if(row >= m || col >= n)
            return 0;
        
        // Base case: If the robot reaches the bottom-right corner, return 1 (found a valid path)
        if(row == m-1 && col == n-1)
            return 1;
        
        // Recursive cases: Explore paths by moving right and down
        int right = solve(row, col+1, m, n); // Move right
        int down = solve(row+1, col, m, n);  // Move down
        
        // Total paths from current position are sum of paths going right and down
        return right + down;
    }
    
    int uniquePaths(int m, int n) {
        // Approach : Recursion 
        
        // Start from the top-left corner and compute paths
        return solve(0, 0, m, n);
    }
};
