#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int left = 0, right = 1; // Left (Buy) & Right (Sell)
        int maxProfit = 0;

        while (right < prices.size()) {
            // If the stock price on the selling day is higher than the buying day
            if (prices[right] > prices[left]) {
                // Calculate the profit and update maxProfit if it's higher
                int profit = prices[right] - prices[left];
                maxProfit = std::max(maxProfit, profit);
            } else {
                // If the selling price is not higher, update the buying day
                left = right;
            }

            right++; // Move to the next day
        }

        return maxProfit;
    }
};
