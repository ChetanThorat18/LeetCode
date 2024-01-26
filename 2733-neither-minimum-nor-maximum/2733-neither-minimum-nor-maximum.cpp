#include <vector>

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        // Check if the array has less than 3 elements
        if (nums.size() < 3)
            return -1;

        // Initialize variables to store the minimum, maximum, and third value
        int a = min(nums[0], nums[1]);
        int b = max(nums[0], nums[1]);
        int c = nums[2];

        // Check if c is neither the maximum nor the minimum
        if (c < b && c > a)
            return c;

        // Check if a is not the minimum
        if (c < a)
            return a;

        // Check if b is not the maximum
        if (c > b)
            return b;

        // If none of the conditions are met, return -1
        return -1;
    }
};
