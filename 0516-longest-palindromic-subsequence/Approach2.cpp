class Solution {
public:
    int n;
    vector<vector<int>>dp;

    int LCS(string s1, string s2, int i, int j) {
        // If either index goes out of bounds, return 0 (base case)
        if (i >= n || j >= n)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        // If characters match, add 1 to the result and move both indices forward
        if (s1[i] == s2[j])
            return dp[i][j] = 1 + LCS(s1, s2, i + 1, j + 1);

        // If characters do not match, find the maximum of moving either index forward
        return dp[i][j] = max(LCS(s1, s2, i, j + 1), LCS(s1, s2, i + 1, j));
    }

    int longestPalindromeSubseq(string s1) {
        n = s1.length(); 
        string s2 = s1; // Copy the input string
        reverse(s2.begin(), s2.end()); // Reverse the copied string to get the reverse of s1

        dp.assign(n , vector<int>(n,-1));

        // Find the length of the longest common subsequence between s1 and its reverse
        return LCS(s1, s2, 0, 0);
    }
};
