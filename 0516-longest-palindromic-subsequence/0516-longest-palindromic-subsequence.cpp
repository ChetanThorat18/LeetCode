class Solution {
public:

    int longestPalindromeSubseq(string s1) {
        // Approach: Bottom-up DP (Tabulation)

        int n = s1.size();
        string s2 = s1;
        reverse(s2.begin(),s2.end());

        // Create a 2D DP array to store the lengths of LCS for subsequences of text1 and text2
        // dp[i][j] represents the length of LCS of text1[0...i-1] and text2[0...j-1]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
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
        return dp[n][n];
    }
};