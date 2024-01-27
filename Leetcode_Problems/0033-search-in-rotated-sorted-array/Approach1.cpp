class Solution {
public:
// Function to find the pivot index, the index where rotation occurs
    int findPivot(vector<int>& nums,int n){
        int l = 0, r = n-1;

        while(l < r){
            int mid = l + (r-l)/2;
            // If the middle element is greater than the last element, the pivot is in the right half(like finding minimum in rotated sorted array)
            if( nums[mid] > nums[r] ){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }

        return r; // index of the pivot
    }

    int binarySearch(int low,int high,vector<int>& nums, int target){

        while( low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] ==  target){
                return mid;
            }
            else if ( nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        // Approach :   Perform binary search in the left and right sorted halves separately by finding the pivot index at which array is rotated
        int n = nums.size();

        int pivotIndex = findPivot(nums,n);

        int idx = binarySearch(0,pivotIndex-1,nums,target);

        if( idx != -1)
            return idx;

        idx = binarySearch(pivotIndex,n-1,nums,target);
            return idx;

    }
};
