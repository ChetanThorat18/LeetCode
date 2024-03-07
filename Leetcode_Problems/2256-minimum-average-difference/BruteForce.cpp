class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        // Get the size of the input array
        int n = nums.size();

        // Initialize variables to store the index with the minimum average difference
        // and the minimum difference itself
        int index = -1;
        int minDiff = INT_MAX;

        // Iterate through each index of the array
        for(int i = 0; i < n; i++) {
            // Calculate the sum of elements from index 0 to i (inclusive)
            long long leftSum = 0;
            for(int j = 0; j <= i; j++) {
                leftSum += nums[j];
            }

            // Calculate the average of the left part
            int leftAverage = leftSum / (i + 1);

            // Calculate the sum of elements from index i+1 to n-1 (inclusive)
            long long rightSum = 0;
            for(int j = i + 1; j < n; j++) {
                rightSum += nums[j];
            }

            // Calculate the average of the right part
            int rightAverage = 0;
            if(i != (n - 1)) { // Ensure there are elements in the right part
                rightAverage = rightSum / (n - i - 1);
            }

            // Calculate the absolute difference between the left and right averages
            int diff = abs(leftAverage - rightAverage);

            // Update the minimum difference and corresponding index if necessary
            if(diff < minDiff) {
                minDiff = diff;
                index = i;
            }
        }

        // Return the index with the minimum average difference
        return index;
    }
};
