class Solution {
public:
    int n;

    // Recursive function to find the length of the longest increasing subsequence
    // idx: the current index in the nums array
    // prevIdx: the index of the previous element in the subsequence
    int solve(vector<int>& nums, int idx, int prevIdx) {
        // Base case: If we have processed all elements, return 0
        if (idx >= n)
            return 0;

        // Initialize the length of the subsequence if we take the current element
        int take = 0;

        // Check if we can include the current element in the subsequence
        if (prevIdx == -1 || nums[prevIdx] < nums[idx]) {
            // Recursively find the length of the subsequence including the current element
            take = 1 + solve(nums, idx + 1, idx);
        }

        // Recursively find the length of the subsequence excluding the current element
        int skip = solve(nums, idx + 1, prevIdx);

        // Return the maximum length of the subsequence obtained by either including or excluding the current element
        return max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        // Approach : Recursion
        n = nums.size();

        // Start the recursion from the first element with no previous element
        return solve(nums, 0, -1);
    }
};
