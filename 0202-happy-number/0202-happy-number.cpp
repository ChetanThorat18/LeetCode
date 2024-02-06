class Solution {
public:
   
    bool isHappy(int n) {
        while (n > 9) {
            int sum = 0;
            
            // Calculate the sum of squares of digits.
            while (n) {
                int digit = n % 10;
                n = n / 10;
                sum = sum + (digit * digit);
            }
            
            n = sum;  // Update n with the sum for the next iteration.
        }

        // If the final value of n is 1 or 7, it's a happy number.
        return (n == 1 || n == 7);
    }
};