class Solution {
public:
    int n;

    int dp[100001][2];

    // Recursive function to determine the minimum flips needed to make the string monotone increasing
    int solve(string &s, int curr_idx, int prev_val) {
        // Base case: If we've processed all characters in the string, no more flips are needed
        if (curr_idx >= n)
            return 0;

        if(dp[curr_idx][prev_val] != -1)
            return dp[curr_idx][prev_val];

        int flip = INT_MAX;    
        int no_flip = INT_MAX; 

        // Check the current character in the string
        if (s[curr_idx] == '0') {
            if (prev_val == 0) {
                // If previous value was '0', we have two options:
                // 1. Flip current '0' to '1' and move to next character with previous value as '1'
                flip = 1 + solve(s, curr_idx+1, 1);
                // 2. Keep current '0' as '0' and move to next character with previous value as '0'
                no_flip = solve(s, curr_idx+1, 0);
            } else {
                // If previous value was '1', we must flip current '0' to '1' to maintain monotonicity
                flip = 1 + solve(s, curr_idx+1, 1);
            }
        } else if (s[curr_idx] == '1') {
            if (prev_val == 0) {
                // If previous value was '0', we have two options:
                // 1. Flip current '1' to '0' and move to next character with previous value as '0'
                flip = 1 + solve(s, curr_idx+1, 0);
                // 2. Keep current '1' as '1' and move to next character with previous value as '1'
                no_flip = solve(s, curr_idx+1, 1);
            } else {
                // If previous value was '1', we simply move to the next character with previous value as '1'
                no_flip = solve(s, curr_idx+1, 1);
            }
        }

        // Return the minimum of the two options: flipping or not flipping the current character
        return dp[curr_idx][prev_val] = min(flip, no_flip);
    }

    int minFlipsMonoIncr(string s) {
        // Approach : Recursion + Memoization
        n = s.length(); 

        memset(dp, -1 , sizeof dp);
        // Start the recursion with the initial index 0 and previous value as '0'(eg- for string to be monotonic it should start with 0)
        return solve(s, 0, 0); 
    }
};
