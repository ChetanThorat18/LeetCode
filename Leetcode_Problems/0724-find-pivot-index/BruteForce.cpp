class Solution {
public:
    int pivotIndex(std::vector<int>& nums) {
        // Brute Force Approach O(n^2)
        
        int n = nums.size();
        
        
        for(int i = 0; i < n; i++) {

            int leftSum = 0;
            // Calculate the sum of elements to the left of the current index
            for(int j = 0; j < i; j++) {
                leftSum += nums[j];
            }
            
            int rightSum = 0;
            // Calculate the sum of elements to the right of the current index
            for(int k = i + 1; k < n; k++) {
                rightSum += nums[k];
            }
            
            // If the sum of elements to the left is equal to the sum of elements to the right,
            // then the current index is the pivot index
            if(leftSum == rightSum) {
                return i;
            }
        }
        
        // If no pivot index is found, return -1
        return -1;
    }
};
