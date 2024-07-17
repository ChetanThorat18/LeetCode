class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Sort the array to bring duplicate elements together.
        sort(nums.begin(), nums.end());

        int moves = 0;

        // Step 2: Traverse the sorted array from the second element to the end.
        for (int i = 1; i < n; i++) {
            // If the current element is less than or equal to the previous element,
            // we need to make it unique by incrementing it.
            if (nums[i] <= nums[i - 1]) {
                // Calculate the number of moves needed to make nums[i] greater than nums[i-1].
                moves += (nums[i - 1] - nums[i] + 1);
                // Update the current element to its new unique value.
                nums[i] = nums[i - 1] + 1;
            }
        }
        
        return moves;
    }
};
