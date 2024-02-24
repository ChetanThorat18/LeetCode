class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // Approach : PrefixSum Without using extra space
        // Time Complexity : O(n)
        // Space Complexity : O(1)

        int n = nums.size();

        int totalArraySum = 0;
        // Calculate the total sum
        for(int &num : nums){
            totalArraySum += num;
        }

        int prefixSum = 0;
        for(int i=0; i<n; i++){

            int leftSum = prefixSum ;       
            
            int rightSum = totalArraySum - prefixSum - nums[i];

            // If the sum of elements to the left is equal to the sum of elements to the right,
            // then the current index is the pivot index
            if( leftSum == rightSum)
                return i;

            // Update the prefix sum for the next iteration
            prefixSum += nums[i];
        }

        // If no pivot index is found, return -1
        return -1;
    }
};