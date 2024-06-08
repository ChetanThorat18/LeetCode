class Solution {
public:
    int findComplement(int num) {

        int result = 0;   // Initialize result to store the complement
        int setBit = 1;   // Initialize setBit to set the bit in the result 

        while(num) {  // Continue until all bits of num are processed
            int currBit = (num & 1);  // Get the least significant bit of num
            if(currBit == 0) {  // If the current bit is 0 in num, it should be 1 in the complement
                result = result | setBit;  // Set the corresponding bit in the result using OR operation
            }

            num = num >> 1;  // Right shift num by 1 to process the next bit
            setBit = setBit << 1;  // Left shift setBit by 1 to update the position for the next bit
        }

        return result;  
    }
};