class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        // Approach : Bottom-Up DP
        
        int n = questions.size();
        
        // Initialize a dp array to store maximum points that can be earned up to each question
        // State : dp[i] ==> Maximum points earned from questions from i to n-1
        vector<long long> dp(n + 1, 0);
        
        // Iterate from the last question to the first
        for (int i = n - 1; i >= 0; --i) {
            // Option 1: Solve the current question
            long long solveQ = questions[i][0];
            if (i + questions[i][1] + 1 < n) {
                solveQ += dp[i + questions[i][1] + 1];
            }
            
            // Option 2: Skip the current question
            long long skipQ = dp[i + 1];
            
            // Store the maximum points that can be earned up to the current question
            dp[i] = max(solveQ, skipQ);
        }
        
        // Return the maximum points that can be earned by the end of the exam
        return dp[0];
    }
};