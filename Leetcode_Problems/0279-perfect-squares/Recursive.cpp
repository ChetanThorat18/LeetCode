class Solution {
public:
    int solve(int n) {
        // Base case: If 'n' is 0, return 0 (no perfect square needed)
        if (n == 0)
            return 0;

        // Initialize the minimum count of perfect squares needed to a large value
        int minCount = INT_MAX;

        // Iterate through perfect squares less than or equal to 'n'
        for (int i = 1; i * i <= n; i++) {
            // Recursively calculate the count of perfect squares for the remaining sum
            int result = 1 + solve(n - (i * i));

            // Update the minimum count
            minCount = min(minCount, result);
        }

        return minCount;
    }

    int numSquares(int n) {
        // Approach: Recursion with backtracking
        
        return solve(n);
    }
};
