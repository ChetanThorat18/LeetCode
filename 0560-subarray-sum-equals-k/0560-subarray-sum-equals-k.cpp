class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // Approach: Cumulative Sum / Prefix Sum ==> O(n)
        // unordered map to store cumulative sums along with their frequencies
        unordered_map<int, int> mp;  
        int count = 0; 
        int cummSum = 0;
        // Initially cummSum = 0 , So we have seen cumSum = 0 , 1 time 
        // This handles corner cases . If we don't insert this initially , it gives wrong output 
        // eg - nums = [1,-1] , k = 0  
        mp.insert({0, 1});        
        // Iterate through each element in the input array
        for (int &num : nums) {
            cummSum += num; // Update the cumulative sum
            
            // Calculate the difference between the current cumulative sum and k
            int diff = cummSum - k;
            
            // If the map contains the difference, increment the count by the frequency of the difference
            if (mp.find(diff) != mp.end()) {
                count += mp[diff];
            }
            
            // Increment the frequency of the current cumulative sum in the map
            mp[cummSum]++;
        }       
        return count; 
    }
};

/*
    Intuition :
                    i     j      
    Let nums = [ 1  4  1  2  6 ]  and    k = 3
    ==>  
    Cummulative-Sum till i => 5 (1+4)
    Cummulative-Sum till j => 8 (1+4+1+2)

    Since Cummulative-Sum till j is 8 , and till i is 5 ,
    There definitely Exists a subarray in between of totalSum = 3   i.e totalSum = k

    So , Approach is , We will check if , have we seen the diff (cummSum - k) in past , 
    If yes , then increase count since subarray with sum = k exists , 

    For eg - Cummulative-Sum till j => 8 , So we will check whether have we seen diff , cummSum - k i.e (8-3 = 5) in past
    In this case , Yes , So increase count as many times as we have seen diff in past
*/