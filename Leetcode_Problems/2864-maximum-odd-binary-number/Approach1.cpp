class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();

        // Initialize a string to store the resulting maximum odd binary number
        string result = string(n, '0');

        // Initialize pointers for Most Significant Bit (MSB) and Least Significant Bit (LSB)
        int MSB = 0;
        int LSB = n - 1;

        for (char& ch : s) {
            // If the current character is '1', place it in the resulting string
            if (ch == '1') {
                // If the LSB of the result is '1', place '1' at MSB and increment MSB
                if (result[LSB] == '1') {
                    result[MSB] = '1';
                    MSB++;
                } 
                // Otherwise, place '1' at LSB
                else {
                    result[LSB] = '1';
                }
            }
        }

        return result;
    }
};

/*
    Approach : 
        For a  number to be odd , its LSB must be 1 .
        So , for first encountered '1' , we will set LSB of result to '1'

        For a number to be maximum , its MSB must be set to '1' .
        So , for all subsquent '1' s encountered , set MSB of result to '1'
*/
