class Solution {
public:
    bool isPowerOfTwo(int n) {
        if( n <= 0)
            return false;

        return (n & (n-1) ) == 0;
    }
};

/*
    Let n = 8 
     Binary representation:
       - n      : 1000
       - n - 1  : 0111
     Perform bitwise AND operation:
       1000
     & 0111
     --------
       0000


    When n is power of 2 , and if we subtract 1 from n , It negates all bits
    which eventually gives BITWISE AND result 0 

*/
