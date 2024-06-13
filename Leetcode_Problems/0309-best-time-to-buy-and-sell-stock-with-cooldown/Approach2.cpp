class Solution {
public:
    int n;
    int dp[50001][2];

    int solve(vector<int>& prices , int day , bool buy){
        // Base case: If we've reached the end of the array, return 0 (no more transactions possible)
        if(day >= n)
            return 0;

        int profit = 0;

        if(dp[day][buy] != -1)
            dp[day][buy];

        // If we can buy
        if(buy){ 
            // Option 1: Buy the stock and proceed to the next day with selling possibility (cooldown)
            int take = solve(prices , day+1, false) - prices[day];
            // Option 2: Do not buy the stock and proceed to the next day with buying possibility
            int not_take = solve(prices , day+1, true);
            // Choose the maximum profit among the two options
            profit = max({profit , take, not_take});
        }
         // If we can sell
        else{
            // Option 1: Sell the stock on the current day and skip the next day (cooldown)
            int sell  = prices[day] + solve(prices , day+2, true);
            // Option 2: Do not sell the stock and proceed to the next day with selling possibility
            int not_sell = solve(prices , day+1, false);
            // Choose the maximum profit among the two options
            profit = max({profit,sell,not_sell});
        }

        return dp[day][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        // Approach : Recursion with Memoization
        n = prices.size();

        memset(dp,-1,sizeof(dp));
        
        bool buy = true; // Initially, we can buy the stock
        return solve(prices , 0 , buy);
    }
};
