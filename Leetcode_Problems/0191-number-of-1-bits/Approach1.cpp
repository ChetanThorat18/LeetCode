class Solution {
public:
    int hammingWeight(uint32_t n) {

       int count = 0;

       // Iterate through each bit in the 32-bit binary representation
       for(int i=31; i>=0; i--){
            // Extract the i-th bit
           int bit = (n >> i) & 1;

           if(bit == 1)
            count++;
       }  

       return count;
    }
};
