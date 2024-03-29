class Solution {
public:
    bool binarySearch(vector<int>& arr,int target){
        int low = 0;
        int high = arr.size()-1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(arr[mid] == target){
                return true;
            }else if(arr[mid] > target){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return false;

    }

    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // Binary Search Approach : Time Complexity  O(n1 * log(n2) )
        for(int &num : nums1){
            // Perform binary search on nums2 for each element of nums1
            if( binarySearch(nums2, num) ){
                return num; // Common element found
            }
        }

        return -1; // No common element found
    }
};
