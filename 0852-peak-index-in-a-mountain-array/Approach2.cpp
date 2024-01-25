class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
      // Linear Approach : O(n)

      int n = arr.size(), i=0;

      // Move to the next index as long as the array is strictly increasing
      while( i < n-1  && arr[i] < arr[i+1]){
          i++;
      }  

      return i;
    }
};
