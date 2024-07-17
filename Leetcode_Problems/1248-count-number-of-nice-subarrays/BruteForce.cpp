class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // Brute Force

        int n = nums.size(); 

        int result = 0; 

        // Iterate through all possible subarrays
        for(int i=0; i<n; i++){
            int oddCount = 0; // Initialize a counter for odd numbers
            for(int j=i; j<n; j++){
                if(nums[j] % 2 != 0){ // If the current number is odd
                    oddCount++; // Increment the count of odd numbers
                }
                if(oddCount == k){ // If we have found exactly k odd numbers in the subarray
                    result++; // Increment the result counter
                }
            }
        }

        return result; // Return the total number of nice subarrays found
    }
};
