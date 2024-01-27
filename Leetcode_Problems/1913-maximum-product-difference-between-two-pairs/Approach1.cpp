class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
       // For the difference of (a*b) - (c*d) to be maximum , (a*b) should be largest and (c*d) should be smallest

       // Approach 1 : Time Complexity O(nlogn) (to sort array)

       // largest (a*b) => last two elements in sorted array
       // smallest (c*d) =>  first two elements in sorted array

        int n = nums.size();
       sort(nums.begin(),nums.end());
       return (nums[n-1] * nums[n-2]) - (nums[0] * nums[1]);
    }
};
