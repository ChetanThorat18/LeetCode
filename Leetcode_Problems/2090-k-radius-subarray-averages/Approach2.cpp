class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        // Prefix Sum Approach
        
        // If k is 0, return the input array since there's no need to calculate averages
        if (k == 0)
            return nums;

        int n = nums.size();
        vector<int> result(n, -1); 

        // If the size of the array is less than (2 * k + 1), it's not possible to calculate the k-radius averages
        if (n < (2 * k + 1))
            return result;


        vector<long long> prefixSum(n, 0); 
        prefixSum[0] = nums[0]; 
        // Calculate the prefix sum of the array
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        // Calculate the averages for each window
        for (int i = k; i < n - k; i++) {
            int left_idx = i - k; // Calculate the left index of the window
            int right_idx = i + k; // Calculate the right index of the window

            long long sum = prefixSum[right_idx]; // Calculate the sum of the elements from index 0 to right_idx

            // If the left index is greater than 0, subtract the prefix sum at left_idx - 1 to get the sum of the window
            if (left_idx > 0) {
                sum -= prefixSum[left_idx - 1];
            } 

            // Calculate the average of the window and store it in the result array
            int avg = sum / (2 * k + 1);
            result[i] = avg;
        }

        return result;
    }
};

/*
    Input: nums = [7,4,3,9,1,8,5,2,6], k = 3
    Output: [-1,-1,-1,5,4,4,-1,-1,-1]


    For i = 4:
        - Left Index: i - k = 4 - 3 = 1
        - Right Index: i + k = 4 + 3 = 7

        The subarray centered at index 4 with a radius of 3 is [9, 1, 8, 5, 2].

        PrefixSum array: [7, 11, 14, 23, 24, 32, 37, 39, 45]
                        ^   ^   ^   ^   ^   ^   ^   ^   ^
                        |   |   |   |   |   |   |   |   |
                        0   1   2   3   4   5   6   7   8

        Sum of Subarray:
            Sum = prefixSum[7] - prefixSum[1 - 1] = prefixSum[7] - prefixSum[0] = prefixSum[7]

        Average of Subarray:
            Average = Sum / (2 * k + 1) = prefixSum[7] / 7 = 39 / 7 = 5.571 ≈ 5 (integer division)


*/

