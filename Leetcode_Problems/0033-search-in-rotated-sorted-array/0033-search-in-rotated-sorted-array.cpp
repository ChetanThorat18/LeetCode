class Solution {
public:
    int search(vector<int>& nums, int target) {
/*
Since array is rotated, it retains some properties of sorted arrays that we can leverage. Specifically, one half of the array (either the left or the right) will always be sorted. This means we can still apply binary search by determining which half of our array is sorted and whether the target lies within it.
*/
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Check which half is sorted and perform binary search accordingly
            if (nums[left] <= nums[mid]) {
                // Left half is sorted
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                // Right half is sorted
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        // If the loop exits, the target is not found in the array
        return -1;
    }
};