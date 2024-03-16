class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Brute Force
        // Find All possible subarrays
        // And for each of subarray check whether its sum equals to k

        int n = nums.size();

        int count = 0;

        // Iterate over all possible subarrays, starting from each index in the array
        for (int start = 0; start < n; start++) {
            for (int end = start; end < n; end++) { // Iterate over all subarrays starting from 'start' index

                int currSum =0; 

                // Calculate the sum of the current subarray by iterating from  start to end
                for (int idx = start; idx <= end; idx++) {
                    currSum += nums[idx];
                }

                // If the sum of the current subarray equals k, increment the  count
                if (currSum == k) {
                    count++;
                }
            }
        }
        return count;
    }
};
