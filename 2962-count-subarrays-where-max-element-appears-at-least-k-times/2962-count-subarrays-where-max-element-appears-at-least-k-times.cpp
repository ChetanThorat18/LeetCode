class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // Approach :  sliding window 
        int n = nums.size(); 

        // Find the maximum element in the array
        int maxElement = *max_element(nums.begin(),nums.end()); 

        long long result = 0;
        int countMax = 0; 

        int i = 0, j = 0; 
        while (j < n) { 
            // If the current element is the maximum element
            if (nums[j] == maxElement) { 
                countMax++; // Increment the count of occurrences
            }

            // If the count of occurrences of the maximum element is at least k
            while (countMax >= k) { 
                // Increment the result by the number of subarrays ending at index j
                result += (n - j); 

                 // If the left pointer element is the maximum element
                if (nums[i] == maxElement) {
                    countMax--; // Decrement the count of occurrences
                }

                i++; // shrink the window to find next set of valid subarrays
            }

            j++; 
        }

        return result; 
    }
};



/*
    Intuition behind ,  result += (n-j)

    eg - nums = [1,3,2,3,3], k = 2

         i           j
         1   3   2   3   3

         consider at this point , we have a subaray in which maxElement(i.e. 3) appears exactly k(i.e. 2) times 

         So this is a valid subarray as per problem defintion.

         So , by extending this subarray using j , we will get more valid subarrays irrespective of whether nums[j] is maxElement or not ,
         since we need at least k occurences of maxElement in current subarray . 

         So , at this point , no. of valid subarrays will be (n-j) i.e   5-3  ==> 2
         i.e    [1] =>   [1  3  2  3]
                [2] =>   [1  3  2  3  3] 
*/