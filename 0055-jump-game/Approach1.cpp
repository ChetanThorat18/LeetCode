class Solution {
public:
    int n; 

    bool solve(vector<int>& nums, int idx) {
        // If the current index is the last index, return true
        if (idx == n - 1)
            return true;

        // Iterate through all possible jump lengths from the current index
        for (int i = 1; i <= nums[idx]; i++) {
            // Check if it's possible to reach the last index starting from the next index after jumping 'i' steps
            if (solve(nums, idx + i) == true)
                return true;
        }

        // If none of the jumps from the current index lead to the last index, return false
        return false;
    }

    bool canJump(vector<int>& nums) {
        // Approach : Recursion
        n = nums.size();

        // Call the recursive function starting from the first index (index 0)
        return solve(nums, 0);
    }
};
