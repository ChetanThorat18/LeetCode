class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // Approach: Bottom-up DP (Tabulation)

        int n = text1.size();
        int m = text2.size();

        // Create a 2D DP array to store the lengths of LCS for subsequences of text1 and text2
        // dp[i][j] represents the length of LCS of text1[0...i-1] and text2[0...j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    // If the characters at current positions match, increment the length of LCS
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    // If the characters don't match, take the maximum length of LCS from either
                    // excluding the last character of text1 or excluding the last character of text2
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Return the length of LCS of the entire strings text1 and text2
        return dp[n][m];
    }
};