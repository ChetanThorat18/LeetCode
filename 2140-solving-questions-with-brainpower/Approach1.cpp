class Solution {
public:
    int n; 

    long long solve(vector<vector<int>>& questions, int idx){
        // Base case: If idx is out of bounds, return 0(No points will be earned)
        if(idx >= n)
            return 0;

        // Option 1: Solve the current question and recursively solve subsequent questions(by skipping next brainpower_i questions)
        long long solveQ = questions[idx][0] + solve(questions, idx + questions[idx][1] + 1);

        // Option 2: Skip the current question and move to the next one
        long long skipQ = solve(questions, idx + 1);

        // Return the maximum points between solving and skipping the current question
        return max(solveQ, skipQ);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size(); 

        return solve(questions, 0); 
    }
};
