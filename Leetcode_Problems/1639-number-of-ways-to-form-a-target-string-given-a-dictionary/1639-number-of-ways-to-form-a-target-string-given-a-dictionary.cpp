class Solution {
public:
    const int MOD = 1e9+7; 

    int numWays(vector<string>& words, string target) {
        // Bottom Up DP
        
        int k = words[0].size(); // Number of columns in words (length of each word)
        int m = target.length(); // Length of the target string
        
        // Create a frequency matrix to count occurrences of each character in each column
        vector<vector<long long>> freq(26, vector<long long>(k));
        
        // Populate the frequency matrix
        for(int col = 0; col < k; col++) {
            for(string &word : words) {
                freq[word[col] - 'a'][col]++;
            }
        }
        
        // Create a DP table to store the number of ways to form substrings of target
        vector<vector<long long>> dp(m+1, vector<long long>(k+1));
        
        dp[0][0] = 1; // Base case: There's 1 way to form the empty substring of target
        
        // Iterate through the DP table
        for(int i = 0; i <= m; i++) { // Iterate through target characters
            for(int j = 0; j <= k; j++) { // Iterate through columns of words
                
                // Case 1: Skip the current column
                if(j < k)
                    dp[i][j+1]  = (dp[i][j+1] + dp[i][j]) % MOD;
                
                // Case 2: Use the current character from the current column
                if(i < m && j < k)
                    dp[i+1][j+1] = (dp[i+1][j+1] + freq[target[i] - 'a'][j] * dp[i][j]) % MOD;
            }
        }
        
        return dp[m][k]; // Return the number of ways to form the entire target string
    }
};
