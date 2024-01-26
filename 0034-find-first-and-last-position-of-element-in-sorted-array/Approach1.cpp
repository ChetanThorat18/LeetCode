class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;

        int first=-1,last=-1;

        while(i<=j){
            int mid = (i+j)/2;

            if(nums[mid] == target){
                first = mid;
                last = mid;
                while (first > 0 && nums[first - 1] == target) {
                    first--;
                }
                while (last < nums.size() - 1 && nums[last + 1] == target) {
                    last++;
                }
                break;
            }
            else if (nums[mid] < target) {
                i = mid + 1;
            }
            else {
                j = mid - 1;
            }
        }
        return {first, last};
    }
};
