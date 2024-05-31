class Solution {
public:
    int memo[301][11];
    int solve(vector<int>& jobDifficulty, int n, int idx, int d) {
        // Base case: If only one day left, we will have to complete all remaining jobs in one day
        // So, result will be the maximum difficulty job in the remaining array
        if (d == 1) {
            int maxDifficulty = jobDifficulty[idx];

            for (int i = idx; i < n; i++) {
                maxDifficulty = max(maxDifficulty, jobDifficulty[i]);
            }

            return maxDifficulty;
        }

        if(memo[idx][d] != -1)
            return memo[idx][d];

        int maxDifficulty = jobDifficulty[idx];
        int finalResult = INT_MAX;

        // Iterate from current index 'idx' to 'n - d' to ensure we have enough jobs left to distribute over remaining days
        for (int i = idx; i <= n - d; i++) {
            maxDifficulty = max(maxDifficulty, jobDifficulty[i]);

            // Calculate the result for the current partition and recursively call 'solve' for remaining days
            int result = maxDifficulty + solve(jobDifficulty, n, i + 1, d - 1);

            // Keep track of the minimum difficulty among all partitions
            finalResult = min(finalResult, result);
        }

        return memo[idx][d] = finalResult;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        // Approach : Recursion + Memoization
        int n = jobDifficulty.size();

        // If the number of days is greater than the number of jobs, it's not possible to schedule all jobs
        if (d > n)
            return -1;

        memset(memo , -1 , sizeof(memo));

        // Call the recursive function 'solve' to find the minimum difficulty
        return solve(jobDifficulty, n, 0, d);
    }
};
