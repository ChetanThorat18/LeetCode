class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false; // Negative numbers cannot be palindromes
        }
        
        int original = x; 
        
        long long reversedNumber = 0; 
        
        // Loop until x becomes zero
        while (x > 0) {
            int remainder = x % 10; // Extract the last digit of x
            reversedNumber = reversedNumber * 10 + remainder; // Build the reversed number
            
            // Check for overflow
            if (reversedNumber > INT_MAX) {
                return false; // If overflow occurs, the number cannot be a palindrome
            }
            
            x = x / 10; // Move to the next digit of x by removing the last digit
        } 

        return reversedNumber == original; 
    }
};
