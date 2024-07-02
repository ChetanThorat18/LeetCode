#include <vector>
using namespace std;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;

        // State : dp[i] ==> number of good strings of length i
        vector<int> dp(high + 1, 0);

        // Base case: an empty string "" has 1 way to be a good string of length 0
        dp[0] = 1;

        // Fill DP array for lengths from 1 to high
        for (int i = 1; i <= high; ++i) {

            // Add the number of good strings ending with '0' (exactly zero times)
            if (i - zero >= 0)
                dp[i] = (dp[i] + dp[i - zero]) % MOD;

            // Add the number of good strings ending with '1' (exactly one time)
            if (i - one >= 0)
                dp[i] = (dp[i] + dp[i - one]) % MOD;
        }

        // Calculate the sum of good strings counts from length low to high
        int result = 0;
        for (int i = low; i <= high; ++i) {
            result = (result + dp[i]) % MOD;
        }

        return result;
    }
};