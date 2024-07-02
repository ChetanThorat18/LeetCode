class Solution {
public:
    int Low, High;
    int Zero, One;

    const int MOD = 1e9 + 7;

    int solve(int len) {
        // Base case: if the current length exceeds the high bound, return 0
        if (len > High)
            return 0;

        // Recursively calculate number of good strings by appending '1'
        int append_one = solve(len + One);
        
        // Recursively calculate number of good strings by appending '0'
        int append_zero = solve(len + Zero);

        // Calculate the number of good strings of the current length 'len'
        // If 'len' is within the range [Low, High], count this string itself (1 good string)
        int current_count = (len >= Low && len <= High);

        // Return the total number of good strings including those appended with '0' and '1'
        return (current_count + append_one + append_zero) % MOD;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        Low = low, High = high;
        Zero = zero, One = one;

        // Call the recursive function starting with an empty string (length 0)
        return solve(0);
    }
};
