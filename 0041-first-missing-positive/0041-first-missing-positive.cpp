class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // Approach : Use Numbers as indices
        // Time : O(n) , Space : O(1)

        int n = nums.size(); 

        bool contains_one = false; 

        // First Pass: Adjust the array to ensure only positive integers from 1 to n are considered
        // This is to handle corner cases : if number is greater than n , we cannot access valid index 
        for(int i=0; i<n; i++){
            if(nums[i] == 1){
                contains_one = true; // Mark if 1 is present in the array
            }

            // If the number is non-positive or greater than n, set it to 1
            if(nums[i] <= 0 || nums[i] > n){
                nums[i] = 1;
            }
        } 

        // If 1 is not present in the array, return 1 as the smallest missing positive integer
        if(contains_one == false)
            return 1;

        // Second Pass: Mark the presence of numbers by using their indices
        for(int i=0; i<n; i++){
            int num = abs(nums[i]); // Get the absolute value of the number
            int idx = num - 1; // Convert the number to an index

            // If the number at index 'idx' is positive, mark it as visited by making it negative
            if( nums[idx] > 0 ) {
                nums[idx] = -nums[idx];
            }
        }

        // Third Pass: Find the smallest positive number that is not present
        for(int i=0; i<n; i++){
            // If a positive number is found, return its corresponding index + 1
            if(nums[i] > 0)
                return i+1;
        }

        // If all numbers from 1 to n are present, return n+1 as the smallest missing positive integer
        return n+1;
    }
};
