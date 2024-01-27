#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();

        // Calculate the expected sum of the first n natural numbers
        int totalSum = n * (n + 1) / 2;

        // Initialize sum to store the actual sum of the array elements
        int sum = 0;

        // Calculate the actual sum of the array elements
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }

        // Return the missing number by subtracting the actual sum from the expected sum
        return totalSum - sum;
    }
};
