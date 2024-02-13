class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp; 

        for(int i = 0; i < n; i++) {
             // check if nums[i] has appeared before
            if(mp.count(nums[i])) {
                // calculate the absolute difference between the current index and the last index of appearance
                // if the difference is less than or equal to k, return true
                if(abs(i - mp[nums[i]]) <= k) {
                    return true; 
                }
            }

            // update the last index of appearance for nums[i]
            mp[nums[i]] = i; 
        }

        return false;
    }
};