class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        // Create a hashmap to store the index of each number.
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            // Calculate the complement needed to achieve the target.
            int complement = target - nums[i];

            // Check if the complement is already in the hashmap.
            if (mp.find(complement) != mp.end()) {
                // Return the indices of the two numbers.
                return {i, mp[complement]};
            } else {
                // If complement not found, store the current number and its index in the hashmap.
                mp[nums[i]] = i;
            }
        }
        
        return {};
    }
};
