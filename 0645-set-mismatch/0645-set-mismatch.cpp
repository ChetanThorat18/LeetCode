class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    
        int n = nums.size();

        int missing = -1; 
        int duplicate = -1; 

        // First pass to find the duplicate number
        for(int i = 0; i < n; i++) {

            int idx = abs(nums[i]) - 1; // Get the index corresponding to the current number

            if(nums[idx] < 0) {
                // If the number at this index is already negative, it means we have seen this number before
                duplicate = abs(nums[i]); // This is the duplicate number
            } else {
                // Mark the number at this index as seen by making it negative
                nums[idx] *= -1;
            }
        }

        // Second pass to find the missing number
        for(int i = 0; i < n; i++) {
            // A positive value at index i means the number (i + 1) is missing because it was not marked negative
            if(nums[i] > 0) {
                missing = i + 1; // The missing number
            }
        }

        return {duplicate, missing}; 
    }
};

/*
    When problem hints that numbers in array are in range [1,n] means it hints towards using this numbers as indices 
*/