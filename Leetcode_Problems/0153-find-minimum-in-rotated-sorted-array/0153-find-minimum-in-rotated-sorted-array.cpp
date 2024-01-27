class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0,right = nums.size()-1;


        // condition is not left <= right beacuse it will remain in loop since right is updated to right=mid
        while(left < right){
            int mid = left + (right-left)/2 ;

            // If value at mid is larger than that of value to its right(violating sorting property) 
            // It is sure that right sorted half will have resultant minimum value beacause orginal ascending sorted array is rotated and therefore left sorted half after rotation will have larger values
            // so our search space will be right sorted half
            if(nums[mid] > nums[right]){
                left = mid+1;
            }

            // we are in valid sorted half and  Minimum element must be in the left half or at the mid
            // right is upadte to mid and not mid-1 beacause mid could be minimum and we could lose that
            // eg - 3,4,5,1,2
            else{
                right = mid;
            }
        }

        return nums[left];
    }
};