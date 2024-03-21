class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        string result = string(n, '0');

        // Count the number of '1's in the input string s
        int no_of_Ones = count(s.begin(), s.end(), '1');

        // Initialize an index to traverse the resulting string and place '1's
        int MSB = 0;
        // Loop until there are more than 1 '1's left
        while (no_of_Ones > 1) {
            // Place '1's in the resulting string starting from the MSB
            result[MSB] = '1';
            MSB++;

            // Decrement the count of remaining '1's
            no_of_Ones--;
        }

        // Place the last '1' in the resulting string at the LSB position
        result[n - 1] = '1';

        return result;
    }
};
