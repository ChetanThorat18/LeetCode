#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        // Get the size of the array
        int n = nums.size();

        // Iterate through the range [0, n]
        for (int i = 0; i <= n; ++i) {
            bool found = false;

            // Check if the current number is present in the array
            for (int j = 0; j < n; ++j) {
                if (nums[j] == i) {
                    // Mark as found if the current number is present
                    found = true;
                    break;
                }
            }

            // If the current number is not found, it is the missing number
            if (!found) {
                return i;
            }
        }

        return -1;
    }
};
