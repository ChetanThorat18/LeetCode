class Solution {
public:
    int m; // length of strings in words
    int n; // length of target string

    const int MOD = 1e9 + 7;  // As per constraint

    vector<vector<int>>dp;

    // freq: 2D vector that stores the frequency of each character in each column of words
    // target: the target string we want to form
    // i: current index in target string
    // j: current column index in words
    int solve(vector<vector<long long>>& freq, string target, int i, int j) {
        // Base case 1: If we have formed the entire target, return 1 (one valid way)
        if (i == n)
            return 1;

        // Base case 2: If we have exhausted the columns in words, return 0 (no valid way)
        if (j == m)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        // Calculate the number of ways to form the target if we don't take the current character
        int not_taken = solve(freq, target, i, j + 1) % MOD;

        // Calculate the number of ways to form the target if we take the current character
        // Get the current character from the target string
        // Multiplying by freq because it represents the number of valid choices we have for
        // the current character in the current column
        char target_curr_char = target[i]; 
        int taken = (freq[target_curr_char - 'a'][j] * solve(freq, target, i + 1, j + 1)) % MOD;

        // Return the sum of both cases, taken and not_taken
        return dp[i][j] = (taken + not_taken) % MOD ;
    }

    int numWays(vector<string>& words, string target) {
        // Approach 1 : Recursion + Memoization
        m = words[0].length();
        n = target.length();

        dp.assign(n+1, vector<int>(m+1, -1));

        // Create a frequency table to count the occurrences of each character
        // in each column of words
        vector<vector<long long>> freq(26, vector<long long>(m, 0));

        // Fill the frequency table
        for (int col = 0; col < m; col++) {
            for (string& word : words) {
                char ch = word[col];
                freq[ch - 'a'][col]++;
            }
        }

        // Start the recursive solution from the first character of the target
        // and the first column of words
        return solve(freq, target, 0, 0);
    }
};
