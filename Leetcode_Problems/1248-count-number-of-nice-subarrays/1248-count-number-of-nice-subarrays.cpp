class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size(); 

        unordered_map<int,int> mp; // Use an unordered_map to store frequency of oddCount (i.e < oddCount, freq >)
        int oddCount = 0; // Initialize a variable to count odd numbers
        mp[oddCount] = 1; // i.e We have seen 0 oddCount in past once (initially)

        int result = 0; 
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 != 0)
                oddCount++; // Increment oddCount if current number is odd

            // If there exists an entry in mp such that mp[oddCount - k] exists, add it to result
            if(mp.count(oddCount - k) > 0) {
                result += mp[oddCount - k];
            }

            mp[oddCount]++; // Increment the count of current oddCount in the map
        }

        return result; 
    }
};

/*
    Intuition : 


     oddCount ==>  1   2   2   3   4
    let,   nums = [1   1   2   1   1]   , k = 3                                  
                                   i

    mp ==  0=>1  
           1=>1
           2=>2
           3=>1

    lets assume we are at index i, upto here oddCount = 4, 
    Now we will check whether we have seen oddCount-k (4-3 == 1) in past .
    Since we have seen oddCount = 1 in past , this means we have seen subarray with exactly k odd numbers after that.


    Reason behind incrementing result freq times is (  result += mp[oddCount - k] )
    ===>   
     
     oddCount=> 0   1   1   2
        nums = [4   1   2   1]  ,  k = 1
                            i
        
        mp ==  0=>2
               1=>2

    lets assume we are at index i, upto here oddCount = 2,
    Now we will check whether we have seen oddCount-k (2-1 == 1) in past .
    Yes, We have seen 1 oddCount ==> 2 times in past , hence we will add 2 to result because 
    after 1 oddCount(idx = 1, idx = 2) there are two subarrays with exactly 1 oddCount.

    first 1 oddCount is at index 1 ==> Subarray after that with 1 oddCount is {2,1}
    second 1 oddCount is at index 2 ==> Subarray after that with 1 oddCount is {1}

   
*/