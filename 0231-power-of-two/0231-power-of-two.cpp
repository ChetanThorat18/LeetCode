class Solution {
public:
    bool isPowerOfTwo(int n) {
        if( n <= 0)
            return false;

        return __builtin_popcount(n) == 1;
    }
};

/*
    If number is power of 2 , It has only one set bit

    eg- 1 => (0001)
        2 => (0010)
        8 => (1000)
        16 => (10000)
        32 => (100000)
*/