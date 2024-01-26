class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        // the desired index is between [low, high+1]
        while(low <= high){
            int mid = (low + high) / 2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1 ;
            }
        }
        // At this point , low > high (i.e low = high + 1)
        // since target will always have index in between [low , high+1 (initially n)]
        // i.e. target has index in [low , low] as high+1 = low now
        return low;
    }
};