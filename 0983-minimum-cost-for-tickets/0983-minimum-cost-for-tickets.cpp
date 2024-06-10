class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // Approach : Bottom-Up DP (Tabulation)
        int n = days.size();

        // Use an unordered set to quickly check if a given day is a travel day
        unordered_set<int> travelDays(days.begin(), days.end());

        // The last day of travel in the year
        int last_day = days[n - 1];

        // Create a DP array to store the minimum cost up to each day
        // State : dp[i] ==> Minimum cost to travel till day i 
        vector<int> dp(last_day + 1, 0);

        for (int i = 1; i <= last_day; i++) {

            // If the current day is not a travel day, the cost remains the same as the previous day
            if (travelDays.find(i) == travelDays.end()) {
                dp[i] = dp[i - 1];
            } 

            else {
                // Calculate the cost if buying a 1-day pass
                int one_day_pass = costs[0] + dp[i - 1];

                // Calculate the cost if buying a 7-day pass
                // Use max(i - 7, 0) to handle the case when i is less than 7
                int seven_day_pass = costs[1] + dp[max(i - 7, 0)];

                // Calculate the cost if buying a 30-day pass
                // Use max(i - 30, 0) to handle the case when i is less than 30
                int thirty_day_pass = costs[2] + dp[max(i - 30, 0)];

                // Choose the minimum cost among the three options
                dp[i] = min({one_day_pass, seven_day_pass, thirty_day_pass});
            }
        }

        // The minimum cost to cover all travel days is stored in dp[last_day]
        return dp[last_day];
    }
};
