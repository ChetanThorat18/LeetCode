class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        // Brute Force : For each index check if its left and right subarrays  are smaller or not

        for(int i=1; i<arr.size()-1; i++){
            int num = arr[i];
            int left = i-1, right = i+1;
            bool flag = true;

            // Check if elements to the left of the current index are smaller
            while( left >=0){
                if(arr[left] > num ){
                    flag = false;
                     break;
                }
                left--;   
            }

            // Check if elements to the right of the current index are smaller
            if(flag){
                while(right < arr.size() ){
                    if(arr[right] > num){
                        flag = false;
                        break;
                    }
                    right++;
                }
            }

            // If both left and right subarrays are smaller, return the current index as the peak
            if(flag)
                return i;
        }

        return -1;
        
    }
};
