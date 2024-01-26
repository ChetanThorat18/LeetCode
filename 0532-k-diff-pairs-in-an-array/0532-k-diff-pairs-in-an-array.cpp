class Solution {
public:
    // Binary search function to find the index of key in nums
    int binarySearch(vector<int> nums, int start, int key) {
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == key) {
                return mid;
            } else if (nums[mid] < key) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return -1;
    }

    // Main function to find the number of unique k-diff pairs
    int findPairs(vector<int>& nums, int k) {
        // Sort the array
        sort(nums.begin(), nums.end());

        // Use a set to store unique k-diff pairs
        set<pair<int, int>> result;

        // Iterate through the array to find k-diff pairs
        for (int i = 0; i < nums.size(); i++) {
            // Perform binary search to find the index of nums[i]+k
            int index = binarySearch(nums, i + 1, nums[i] + k);
            
            // If found, add the pair to the result set
            if (index != -1) {
                result.insert({nums[i], nums[index]});
            }
        }

        // Return the number of unique k-diff pairs
        return result.size();
    }
};
