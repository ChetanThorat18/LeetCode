class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        // Initialize two pointers, one at the beginning and one at the end of the array
        int left = 0;
        int right = n - 1;

        int count = 0;

        while (left < right) {
            // If the sum of the elements pointed by left and right pointers is less than the target,
            // it means all elements from left to right-1 will satisfy the condition, 
            // so we update the count by (right - left) and move the left pointer to the right
            if (nums[left] + nums[right] < target) {
                count += (right - left);
                left++;
            }
            // If the sum is greater than or equal to the target, 
            // it means the sum is too large, so we move the right pointer to the left
            else {
                right--;
            }
        }

        return count;
    }
};
