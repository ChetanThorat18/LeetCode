class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //if an element occurs more than n/2 times in the array, it will always occupy the middle position when the array is sorted. 
        // This is because the majority element occurs more than n/2 times, and when the array is sorted, it will occupy the middle position.
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n/2];
    }
};
