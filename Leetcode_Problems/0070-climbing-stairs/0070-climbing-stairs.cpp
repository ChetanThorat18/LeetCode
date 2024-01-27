class Solution {
public:
    // Helper function with memoization
    int climbStairs(int n, int* dp) {
        // Loop to calculate the number of ways to climb each step
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        // Return the result for the nth step
        return dp[n];
    }

    
    // Main function with initialization of memoization array
    int climbStairs(int n) {
        // Create an array for memoization with initial values
        int* dp = new int[n + 1];
        dp[0] = dp[1] = 1;

        // Initialize the array with -1 for memoization
        for (int i = 2; i <= n; i++) {
            dp[i] = -1;
        }

        
        return climbStairs(n, dp);
    }
};

/*
    class Solution {
    public int climbStairs(int n) {
        if (n <= 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        }

        int[] dp = new int[n + 1];
        dp[1] = 1;
        dp[2] = 2;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
    
}
*/
