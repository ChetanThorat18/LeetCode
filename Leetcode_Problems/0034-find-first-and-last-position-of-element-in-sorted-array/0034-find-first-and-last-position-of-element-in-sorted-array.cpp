class Solution {
public:
    // O(2.logn) == O(logn)
    int binSearch(vector<int>& nums, int target,bool isFirstFound){
        int left = 0,right=nums.size()-1; 
         int index = -1;
        while(left <= right){
            int mid = (left+right)/2;
           
            if( nums[mid] < target)
                left = mid+1;
            else if(nums[mid] > target)
                right = mid-1;
            else{
                index = mid;
                if(isFirstFound){
                   // means to find firstPosition hence search in Left 
                    right = mid-1;
                }
                else{
                     // search in right subarray for last position
                    left = mid+1;
                }
            } 
        }
        return index;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = binSearch(nums,target,true);
        int last = binSearch(nums,target,false);

        return {first,last};
    }
};