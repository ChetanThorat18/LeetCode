class Solution {
public:
    int solve(string &str1, string &str2, int n, int m) {
        // Base case: If either of the strings is empty, then there will be no common subsequence ,so return 0
        if (n == 0 || m == 0)
            return 0;

        // If the last characters of both strings are equal, they contribute 1 to the result
        if (str1[n - 1] == str2[m - 1]) {
            // Move to the next characters in both strings and add 1 to the result
            return 1 + solve(str1, str2, n - 1, m - 1);
        } else {
            // If the last characters are not equal, we have two choices:
            // 1. Exclude the last character of str1 and find LCS of str1[0...n-2] and str2[0...m-1]
            // 2. Exclude the last character of str2 and find LCS of str1[0...n-1] and str2[0...m-2]
            int ans1 = solve(str1, str2, n - 1, m);
            int ans2 = solve(str1, str2, n, m - 1);

            // Return the maximum of the two choices
            return max(ans1, ans2);
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        // Approach: Recursion
        
        // Call the recursive function 'solve' to find the length of the LCS
        int n = text1.size();
        int m = text2.size();
        return solve(text1, text2, n, m);
    }
};
