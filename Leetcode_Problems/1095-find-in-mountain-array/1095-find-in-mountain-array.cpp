/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findPeakIndex(MountainArray &mountainArr , int n){
        int left = 0;
        int right = n - 1;

        while(left < right){
            int mid = left + (right - left)/2;

            if( mountainArr.get(mid) < mountainArr.get(mid + 1)  ){
                left = mid + 1;
            }
            else{
                right = mid;
            }

        }
          return left;
    }

    int BinarySearch_LeftHalf(int left , int right , int target , MountainArray &mountainArr){
        int l = left;
        int r = right;

        while(l <= r){
            int mid = l + (r-l)/2;

            if( mountainArr.get(mid) == target ){
                return mid;
            }
            else if( mountainArr.get(mid) > target ){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return -1;
    }

    int BinarySearch_RightHalf(int left , int right , int target , MountainArray &mountainArr){
        int l = left;
        int r = right;

        while(l <= r){
            int mid = l + (r-l)/2;

            if( mountainArr.get(mid) == target ){
                return mid;
            }
            else if( mountainArr.get(mid) > target ){
               l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }

        return -1;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        // Approach : Find Peak index and apply binary search in (0 , peakIndex) and (peakIndex + 1 , n-1)
        int n = mountainArr.length();

        // STEP 1: Find Peak index
        int peak = findPeakIndex(mountainArr , n);

        // STEP 2: Apply Binary Search in Left Half(Ascending Order)
        int result_index = BinarySearch_LeftHalf( 0, peak,  target, mountainArr);

        if( result_index != -1){
            return result_index;
        }

        // STEP 3: Apply Binary Search in Right Half(Descending Order)
        result_index = BinarySearch_RightHalf( peak + 1 , n-1 , target, mountainArr);

        return result_index;
    }
};