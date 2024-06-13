class Solution {
public:
    int n;
    vector<int>dp;

    int solve(vector<int>& days, vector<int> costs, int idx) {
        // Base case: If we've covered all travel days, no cost is needed
        if (idx >= n)
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        // Calculate the cost if we buy a 1-day pass for the current day
        int one_day_pass_cost = costs[0] + solve(days, costs, idx + 1);

        // Find the index for which the 7-day pass will be valid
        int j = idx;
        int pass_valid_till = days[idx] + 7;
        while (j < n && days[j] < pass_valid_till) {
            j++;
        }
        // Calculate the cost if we buy a 7-day pass for the current day
        int seven_day_pass_cost = costs[1] + solve(days, costs, j);

        // Find the index for which the 30-day pass will be valid
        j = idx;
        pass_valid_till = days[idx] + 30;
        while (j < n && days[j] < pass_valid_till) {
            j++;
        }
        // Calculate the cost if we buy a 30-day pass for the current day
        int thirty_day_pass_cost = costs[2] + solve(days, costs, j);

        // Return the minimum cost among the three options
        return dp[idx] = min({one_day_pass_cost, seven_day_pass_cost, thirty_day_pass_cost});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // Approach : Recursion + Memoization
        n = days.size();

        dp.assign(n, -1);

        // Start the recursive process from the first day
        return solve(days, costs, 0);
    }
};
