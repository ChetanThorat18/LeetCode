class Solution {
public:
    // Main function to find the number of distinct k-diff pairs
    int findPairs(vector<int>& nums, int k) {
        // Sort the array
        sort(nums.begin(), nums.end());

        // Set to store distinct k-diff pairs
        set<pair<int, int>> result;

        // Two pointers i and j
        int i = 0, j = 1;

        // Iterate through the array
        while (j < nums.size()) {
            int diff = nums[j] - nums[i];

            // If the difference is equal to k, add the pair to the result set
            if (diff == k) {
                result.insert({nums[i], nums[j]});
                i++, j++;
            } else if (diff > k) {
                // If the difference is greater than k, move i to the right
                i++;
            } else {
                // If the difference is less than k, move j to the right
                j++;
            }

            // Given constraint: i should not be equal to j
            if (i == j) {
                j++;
            }
        }

        // Return the number of distinct k-diff pairs
        return result.size();
    }
};
