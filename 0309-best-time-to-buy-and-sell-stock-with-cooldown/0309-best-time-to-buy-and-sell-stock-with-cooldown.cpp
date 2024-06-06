class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Approach : Bottom-Up DP (Tabulation)

        int n = prices.size();

        if(n == 0 || n==1)
            return 0;

        vector<int>dp(n , 0);
        //dp[i] represents the maximum profit that can be achieved until day i.

        // Initialize the base cases for the first and second days
        dp[0] = 0;
        dp[1] = max(prices[1] - prices[0] , 0);


        for(int i=2; i<n; i++){

            // Initialize today's profit as the same as the previous day
            dp[i] = dp[i-1];
            
            // to sell stock on current day(i) , find best day(j) before i to buy stock
            // i.e Check for potential profit if we buy on a each day before today (j)
            for(int j=0; j<=i-1; j++){

                // Calculate the profit if we sell today after buying on day j
                int todays_profit = prices[i] - prices[j];

                // Find the profit earned before the day of buying on day j
                // if we buy on day j , we cannot buy as well as sell on day j-1 because of cooldown
                int prev_profit = j >= 2 ? dp[j-2] : 0;

                // Update the maximum profit considering the current profit and previous profit
                dp[i] = max(dp[i], todays_profit + prev_profit);
            }
        }

        // The maximum profit is stored at the last day
        return dp[n-1];
    }
};