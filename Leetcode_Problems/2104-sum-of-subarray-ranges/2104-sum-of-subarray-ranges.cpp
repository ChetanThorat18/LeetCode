#include <vector>
#include <algorithm>

class Solution {
public:
    long long subArrayRanges(std::vector<int>& nums) {
        long long res = 0;
        int n = nums.size();

        // Iterate through all possible starting indices
        for (int i = 0; i < n; i++) {
            int minV = nums[i], maxV = nums[i];

            // Iterate through all possible ending indices for the current starting index
            for (int j = i; j < n; j++) {
                // Update the minimum and maximum values
                minV = min(minV, nums[j]);
                maxV = max(maxV, nums[j]);

                // Add the range to the result
                res += maxV - minV;
            }
        }

        return res;
    }
};
