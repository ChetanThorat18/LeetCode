class Solution {
public:
    int findComplement(int num) {
    int mask = 0; // 'mask' will be used to construct a number with all bits set to 1(no of bits will be same as num)
    int bitPosition = 0; // 'bitPosition' keeps track of the current bit position

    // Construct a mask that has all bits set to 1 and is at least as large as 'num'
    while (mask < num)
    {
        // Add 2^bitPosition to 'mask' to set the bitPosition-th bit of 'mask' to 1
        mask = mask + pow(2, bitPosition);
        
        // Move to the next bit position
        bitPosition++;
    }

    // Return the complement by subtracting 'num' from the mask
    // 'mask' is a number with all bits set to 1, covering all bits of 'num'
    // Subtracting 'num' from 'mask' flips all bits of 'num'
    return mask - num;
    }
};
