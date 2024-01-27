class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // Optimized Binary Search Approach
        int n = arr.size();
        int left = 0 , right = n-1;

        while(left < right){
            int mid = left + (right-left)/2;

            // If the value at the middle index is less than the value at the next index,
            // it means the peak is to the right of the middle index 
            if( arr[mid] < arr[mid+1] ){
                left = mid+1;
            }
            else{
            // If the value at the middle index is greater than or equal to the value at the next index
            // it means the peak is at or to the left of the middle index
                right = mid;
                right = mid;
            }
        }

        return left ; // can also return right
    }
};