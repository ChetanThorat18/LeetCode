class Solution {
public:
    // Function to reverse a number
    long long reverseNum(int num) {
        long long rev = 0;
        
        while (num > 0) {
            int digit =  num % 10;
            rev = rev * 10 + digit;

            num = num / 10;
        }
        
        return rev;
    }


    int countNicePairs(vector<int>& nums) {
        // Brute-Force
        int count = 0;
        int n = nums.size();
        
        
        for (int i = 0; i < n-1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                // Calculate the values according to the conditions
                long long LHS = nums[i] + reverseNum(nums[j]);
                long long RHS = nums[j] + reverseNum(nums[i]);
                
                // Check if the pair is nice
                if (LHS == RHS) {
                    count++;
                }
            }
        }
        
        return count;
    }
};
