class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // Brute Force
        int n = nums.size();
        int maxLength = 0;

        // Iterate through all possible subarrays
        for (int start = 0; start < n; start++) {
            int countZero = 0;
            int countOne = 0;

            // Check each subarray starting from start index
            for (int end = start; end < n; end++) {
                // Count the number of zeros and ones in the current subarray
                if (nums[end] == 0)
                    countZero++;
                else
                    countOne++;

                // If the count of zeros and ones is equal, update the maxLength
                if (countZero == countOne)
                    maxLength = max(maxLength, end - start + 1);
            }
        }
        return maxLength;
    }
};
