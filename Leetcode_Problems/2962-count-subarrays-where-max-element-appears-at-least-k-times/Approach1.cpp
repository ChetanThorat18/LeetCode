class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size(); 

        int maxElement = *max_element(nums.begin(),nums.end()); // Find the maximum element in the array

        long long result = 0; 
        vector<int> maxElementIndices; // vector to store the indices of occurrences of the maximum element

        for(int i = 0; i < n; i++) { 
            // If the current element is the maximum element
            if(nums[i] == maxElement) { 
                // Store its index in the maxElementIndices vector
                maxElementIndices.push_back(i); 
            }

            int size = maxElementIndices.size(); 

            // If the size of the maxElementIndices vector is at least k , means we have found a valid subarray 
            if(size >= k) { 
                // Get the index of the kth occurrence from the end
                int last_idx = maxElementIndices[size - k]; 
                result += last_idx + 1; // Increment the result by the number of subarrays ending at index last_idx
            }
        }

        return result; 
    }
};

/*
    Intuitiion : 

    At any point , we will check if we have found at least k occurences of maxElement , 
    if found , we will find last index in maxElementIndices array with which we can form a valid subarray . 

    eg - nums = [1,3,2,3,3,2,3], k = 3

                          0   1   2   3
    maxElementIndices = [ 1   3   4   6]    ==> indices where maxElement appears 

            i                       j
    nums = [1   3   2   3   3   2   3]

    at this point , we will find last_idx in maxElementIndices with which we can form a valid subarray
    i.e   valid subarray ending at j => [ 3  3  2  3]

    so we need last possible index of maxElement with which we are able to form a valid subarray , i.e  3 appearing at index '3'

    To find this last possible index , we will use , maxElementIndices[size - k]
    where size is current size of array maxElementIndices .  
    i.e maxElementIndices[4 - 3 ] => maxElementIndices[1]  => 3 => So this is the last possible index  with which we are able to form a valid subarray.

    < ----------------------------------------------------------------------------------------------------------------->

    So , this is one possible subarray , but at this point , we can find more valid subarrays , by computing 
    ==> last_idx + 1

    Intuition : 

        last_idx = 3 


                          i           j
      nums = [1   3   2   3   3   2   3]

      Here , array between indices i and j is a valid subarray .
      Other valid subarrays are => 

      [1]
                      i               j
      nums = [1   3   2   3   3   2   3]

      
      [2]
                  i                   j
      nums = [1   3   2   3   3   2   3]

      
      [3]
              i                       j
      nums = [1   3   2   3   3   2   3]

      Total valid subarrays , at this point ==> 4

      i.e last_idx + 1 ==>  3 +  1 => 4

*/
