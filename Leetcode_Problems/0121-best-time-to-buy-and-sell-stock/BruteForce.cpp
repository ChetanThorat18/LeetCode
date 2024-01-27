#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int maxProfit = 0;

        // Iterate through each day as a potential buying day
        for (int i = 0; i < prices.size(); i++) {
            int max = 0;

            // Iterate through days after the buying day to find potential selling days
            for (int j = i + 1; j < prices.size(); j++) {
                // Update the maximum selling price encountered so far
                if (prices[j] > max) {
                    max = prices[j];
                }
            }

            // Update maxProfit if the profit on the current buying day is higher
            if (max - prices[i] > maxProfit) {
                maxProfit = max - prices[i];
            }
        }

        return maxProfit > 0 ? maxProfit : 0;
    }
};
