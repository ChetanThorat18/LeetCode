class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
      
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                // Check if the sum of current pair equals the target.
                if (nums[i] + nums[j] == target) {
                    // Return the indices of the two numbers forming the target sum.
                    return {i, j};
                }
            }
        }

        return {};
    }
};
