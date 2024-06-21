class Solution {
public:
    int n; 

    vector<long long>dp;

    long long solve(vector<vector<int>>& questions, int idx){
        // Base case: If idx is out of bounds, return 0(No points will be earned)
        if(idx >= n)
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        // Option 1: Solve the current question and recursively solve subsequent questions(by skipping next brainpower_i questions)
        long long solveQ = questions[idx][0] + solve(questions, idx + questions[idx][1] + 1);

        // Option 2: Skip the current question and move to the next one
        long long skipQ = solve(questions, idx + 1);

        // Return the maximum points between solving and skipping the current question
        return dp[idx] = max(solveQ, skipQ);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        // Approach : Recursion + Memoization
        n = questions.size(); 

        dp.assign(n,-1);

        return solve(questions, 0); 
    }
};
