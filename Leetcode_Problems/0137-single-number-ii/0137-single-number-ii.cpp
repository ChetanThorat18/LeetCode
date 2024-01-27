class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // YT -> codestorywithMIK

        int result =0;
        // we will check all 32 bits of all numbers in array
        for(int k=0;k<32;k++){
            // for k^th bit of all numbers count no. of zero's and no. of one's
            int countZeros = 0;
            int countOnes = 0;
            int temp = 1 << k;  // shift 1 k times left so that we can check k^th bit of that number
            // eg - num = 9 (1001) and we have to check 4th bit of 9 , so we will left shift 1 four times
            // 1<<4 = 1000 , now we will take BITWISE AND operation of 9 & (1<<4)
            // 1001 && 1000 --> 1  , hence we get k^th bit

            for(int &num : nums){
               // if kth bit is zero
                if((num & temp) == 0 )
                    countZeros ++;
                else
                    countOnes++;
            }
            // if %3 gives 1 it means it is the bit of unique number
            // we are not assuming countZero as result is initialized to zero , so we will update only countOnes
            if(countOnes % 3 == 1)
                result = (result | temp);  
            // it means we have to set k^th bit of result as 1 , so take BITWISE OR operation with (1<<k)
            // eg num =9  (1001) and we want to set 3rd bit as 1 , so we left shift one three times (1<<3) i.e 100
            // now take OR opertion ==> 1001 | 0100 => 1101 , so we set 3rd bit to 1
        }
        return result;
    }
};