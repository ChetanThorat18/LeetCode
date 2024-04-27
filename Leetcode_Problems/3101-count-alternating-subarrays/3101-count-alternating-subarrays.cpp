class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();

        long long count = 0;

        for(int i=0; i<n; i++){

            int j=i;

            // Extend the subarray as long as the next element is different
            while((j + 1 < n) && nums[j] != nums[j + 1]) {
                j++;
            }

            // Calculate the length of the current alternating subarray
            int length = j - i + 1;

            // Calculate the number of subarrays that can be formed from the current alternating subarray
            // using the formula (length * (length + 1)) / 2
            count += (long long) length * (length + 1) / 2;

            // update i to j for next alternating subarray 
            i=j;
        }

        return count;
    }
};

/*
    intuition behind ,    count +=  length*(length+1) / 2
    ==>
            i           j
    nums = [1   0   1   0]

    starting with current i, find alternating subarray with maximum length .
    In this case , we have got subarray of length 4 .

    Let's count total no of alternating subarrays in this window.

        Curr_Length = 4

    [A]
            i           j
    nums = [1   0   1   0]

    ==>  {1} , {1,0} , {1,0,1} , {1,0,1,0}     -> count = 4


    [B]
     
                i       j
    nums = [1   0   1   0]

    ==>  {0} , {0,1} , {0,1,0}     -> count = 3


    [C]
                    i   j
    nums = [1   0   1   0]

    ==>  {1} , {1,0}    -> count = 2

    [D]
                        i
                        j
    nums = [1   0   1   0]

    ==>  {0}-> count = 1


    Total_Count = 1 + 2 + 3 + 4   == 10     i.e Sum of first Curr_Length natural numbers . 4(4+1)/2
    ==>  Curr_Length * (Curr_Length + 1 ) / 2   =>  4(4+1)/2   => 10

*/