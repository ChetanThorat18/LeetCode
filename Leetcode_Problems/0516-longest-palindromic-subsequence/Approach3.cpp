class Solution {
public:
    int n; 
    vector<vector<int>> dp; 

    int solve(string s, int i, int j) {
        // Base case: If the start index exceeds the end index, return 0 (no subsequence)
        if (i > j)
            return 0;

        // If the result for this subproblem is already computed, return it
        if (dp[i][j] != -1)
            return dp[i][j];

        // Base case: If the indices are the same, it's a single character, which is a palindrome
        if (i == j)
            return dp[i][j] = 1;

        // If characters at current indices are the same
        if (s[i] == s[j])
            return dp[i][j] = 2 + solve(s, i + 1, j - 1); // Include both characters in the subsequence

        // If characters are different, find the maximum length by either:
        // 1. Excluding the character at the start index
        // 2. Excluding the character at the end index
        return dp[i][j] = max(solve(s, i, j - 1), solve(s, i + 1, j));
    }

    int longestPalindromeSubseq(string s) {
        n = s.length(); 

        dp.assign(n + 1, vector<int>(n + 1, -1));

        // Start solving the problem for the entire string from index 0 to n-1
        return solve(s, 0, n - 1);
    }
};
