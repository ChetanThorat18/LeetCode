class Solution {
public:
    bool judgeSquareSum(int c) {
        long long left = 0;                     
        long long right = sqrt(c);          

        while (left <= right) {           
            
            if (left * left + right * right == c) {                // If we find a pair (left, right) such that a^2 + b^2 = c
                return true;                // Return true
            } else if (left * left + right * right < c) {          // If sum is less than c, increase the left pointer
                left++;
            } else {                       // If sum is greater than c, decrease the right pointer
                right--;
            }
        }

        return false;                      // If no such pair is found, return false
    }
};