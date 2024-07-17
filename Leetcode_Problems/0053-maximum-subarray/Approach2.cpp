class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadane's Algorithm

        int n = nums.size(); 
        
        int maxSum = INT_MIN; 
        int sum = 0; 
        
        for(int i = 0; i < n; i++) {
            sum += nums[i]; // Add the current element to the current subarray sum
            
            if(sum > maxSum) // If the current subarray sum is greater than maxSum so far,
                maxSum = sum; // update maxSum with the current subarray sum
            
            if(sum < 0)
                sum = 0; // If the current subarray sum becomes negative, reset it to 0
        }

        return maxSum; 
    }
};


/*
    Why Reset sum to 0:
        Avoid Negative Contributions: If sum becomes negative, it means that including the current element (nums[i]) in the subarray reduces the overall sum.     
        Hence, continuing to extend the subarray from i would only decrease maxSum.

    Start Fresh: By resetting sum to 0 when it becomes negative, we essentially "cut off" the current subarray and start looking for new potential subarrays from  
    the next index (i + 1). This ensures that we always consider subarrays that contribute positively to maxSum   
*/


/*
    Follow Up : To find the subarray with maximum sum

     int maxSubArray(vector<int>& nums) {
        

        int n = nums.size(); 
        
        int maxSum = INT_MIN; 
        int sum = 0; 

        int Start = -1; ==> Variable to keep track of the starting index of the max subarray
        int End = -1;   ==>  Variable to keep track of the ending index of the max subarray
        int tmpStart = 0;  ===> // Temporary variable to store the starting index of the current subarray
        
        for(int i = 0; i < n; i++) {
            if(sum == 0){
                tmpStart = i;
            }

            sum += nums[i]; 
            
            if(sum > maxSum){
                maxSum = sum;
                Start = tmpStart;
                End = i;
            }
            
            if(sum < 0)
                sum = 0; 
        }

        return maxSum; 
    }

*/
