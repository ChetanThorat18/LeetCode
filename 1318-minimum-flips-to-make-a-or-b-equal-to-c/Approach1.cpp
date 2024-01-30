class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        
        while(  a!=0 ||  b!=0  ||  c!=0){

            // Find Right Most Bit of 'c' (LSB)

            int c_LSB =  c & 1;

            if(c_LSB == 1){
                // To get result 1 for 'OR' operation , at least one '1' is needed
                // So , We will increment Flips if both ,  MSB  of 'a' and  LSB of 'b' are zero

                if( (a & 1) == 0  && (b & 1) == 0  ){
                    flips++;
                } 
            }
            else {
                // c_LSB = 0
                // To get result 0 for 'OR' operation , both bits needs to be zero
                // So , We will increment Flips if either ,  LSB  of 'a' or  LSB of 'b' is 1

                if( (a & 1) == 1)
                    flips++;
                if( (b & 1) == 1)
                    flips++;
            }

            // Right Shift All the three numbers to check next LSB
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return flips;
    }
};

/*
    To find Right Most Bit(LSB) of any number , take & (and) opration with 1
    For eg-  num = 6 (0110)
        LSB = 0110 & 0001  ==> 0

        num = 3 (0011)
        LSB = 0011 & 0001 ==> 1
*/
