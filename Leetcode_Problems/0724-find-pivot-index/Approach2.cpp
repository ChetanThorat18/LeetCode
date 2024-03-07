class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // Approach : PrefixSum 
        // Time Complexity : O(n)
        // Space Complexity : O(n)

        int n = nums.size();

        vector<int>prefixSum(n);
        prefixSum[0] = nums[0];

        // Calculate the prefix sum
        for(int i=1; i<n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i];
        }

        // Calculate the total sum of the array
        int totalArraySum = prefixSum[n-1];

        for(int i=0; i<n; i++){

            // Calculate the sum of elements to the left of the current index
            int leftSum = 0;       
            if( i != 0)
                leftSum =  prefixSum[i-1];

            // Calculate the sum of elements to the right of the current index
            int rightSum = totalArraySum - prefixSum[i];

            // If the sum of elements to the left is equal to the sum of elements to the right,
            // then the current index is the pivot index
            if( leftSum == rightSum)
                return i;
        }

        // If no pivot index is found, return -1
        return -1;
    }
};
