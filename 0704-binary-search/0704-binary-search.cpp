class Solution {
public:
    int solve(vector<int>&nums , int low , int high , int target){
        // Base case
        if(low > high)
            return -1;

        int mid = low + (high - low)/2;

        if(nums[mid] == target)
            return mid;
        else if(nums[mid] < target)
          return  solve(nums,mid+1,high,target);
        else
           return solve(nums,low,mid-1,target);
            
    }

    int search(vector<int>& nums, int target) {
       // Recursive

      return  solve(nums,0,nums.size()-1,target);
    }
};