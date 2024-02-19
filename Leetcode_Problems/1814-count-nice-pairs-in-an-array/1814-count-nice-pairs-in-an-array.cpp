class Solution {
public:
    int M = 1e9 + 7;   // Given that , Take Mod with  10^9 + 7

    int reverseNum(int num){
        int ans = 0;

        while(num > 0){
            int remainder = num % 10;
            ans = ans*10 + remainder;
            num = num / 10;
        }

        return ans;
    }


    int countNicePairs(vector<int>& nums) {
       int n = nums.size();
       unordered_map<int,int>mp;

       // Calculate nums[i] - reverseNum(nums[i]) for each nums[i]
       for(int i=0; i<n; i++){
           nums[i] = nums[i] - reverseNum(nums[i]);
       } 

        int result = 0;
        // Count the occurrences of each value and update the result
        for(int i = 0; i < n; i++){
            result = (result + mp[nums[i]]) % M;  // Add the count of current value to result
            mp[nums[i]]++; // Increment the count of current value
        }
       return result;
    }
};

/*
    Given :
    nums[i] + rev(nums[j]) == nums[j] + rev(nums[i]) 

    Rearranging Eqn , 

    nums[i] - rev(nums[i])  == nums[j] -  rev(nums[j])
 
*/