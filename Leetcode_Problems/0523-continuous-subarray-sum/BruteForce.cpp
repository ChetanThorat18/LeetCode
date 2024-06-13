class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // Brute Force Approach: Check all possible subarrays

        int n = nums.size();

        // Iterate through each possible starting point of the subarray
        for (int i = 0; i < n; i++) {
            int sum = nums[i]; // Initialize sum with the current element

            // Iterate through each possible ending point of the subarray starting from the next element
            for (int j = i + 1; j < n; j++) {
                sum += nums[j]; // Add the current element to the sum

                // Check if the current subarray sum is a multiple of k
                if (sum % k == 0)
                    return true; // If it is, return true
            }
        }

        // If no valid subarray found, return false
        return false;
    }
};
