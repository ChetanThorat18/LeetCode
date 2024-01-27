class Solution {
public:
    int reverse(int x) {
        int result = 0;

        // Continue reversing until x becomes zero
        while (x) {
            // Check for integer overflow before updating result
            if (result > INT_MAX / 10 || result < INT_MIN / 10)
                return 0;

            // Update result by adding the last digit of x
            result = result * 10 + x % 10;

            // Move to the next digit of x
            x = x / 10;
        }

        return result;
    }
};
