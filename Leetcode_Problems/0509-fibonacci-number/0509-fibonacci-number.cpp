class Solution {
public:
    int solve(int n, vector<int>& dp) {
        // Base cases: F(0) = 0, F(1) = 1
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        // If the value of fib(n) has already been computed and stored in dp, return it directly.
        if (dp[n] != -1)
            return dp[n];

        // If fib(n) has not been computed yet, calculate it recursively by summing up fib(n-1) and fib(n-2),
        // and store the result in dp to avoid recomputation.
        return dp[n] = fib(n - 1) + fib(n - 2);
    }

    int fib(int n) {
        // Approach1: Recursion + Memoization

        // Create a vector 'dp' of size n+1 to store the Fibonacci numbers computed so far.
        // Initialize all elements of dp to -1, indicating that no Fibonacci numbers have been computed yet.
        vector<int> dp(n + 1, -1);

        return solve(n, dp);
    }
};