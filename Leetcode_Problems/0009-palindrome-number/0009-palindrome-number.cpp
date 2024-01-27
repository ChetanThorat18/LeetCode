class Solution {
public:
    bool isPalindrome(int x) {
        // Check if x is negative or if x is a multiple of 10 (excluding 0)
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            return false;
        }

        int reversed = 0;

        // Reverse the second half of the number
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x = x / 10;
        }

        // Check for even length palindrome or odd length palindrome
        // For even length, x should be equal to reversed
        // For odd length, x should be equal to reversed/10 (as the middle digit doesn't matter)
        return (x == reversed) || (x == reversed / 10);
    }
};
