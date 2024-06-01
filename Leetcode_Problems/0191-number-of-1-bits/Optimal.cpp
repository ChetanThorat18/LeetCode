class Solution {
public:
    int hammingWeight(int n) {

        // Brian Kernighan's Algorithm: Repeatedly clearing the least significant bit that is set
        // The algorithm works by continuously clearing the least significant bit that is set in 'n' 
        // until 'n' becomes zero. Each time we clear a bit, we increment the count.

        // Time Complexity: O(k), where k is the number of set bits in 'n'

        int count = 0;
        while(n > 0) {
            // Increment the count for every iteration
            count++;

            // Clear the least significant bit that is set in 'n' by performing n & (n-1)
            // This operation clears the rightmost set bit in 'n'
            n = n & (n - 1);
        }

        return count; 
    }
};


/*
    eg n = 12 ( 1 1 0 0)

    i) n > 0 so count =1
    unset the first rightmost bit that is set by operation n&(n-1)
    n & (n-1) ==>  12 & 11 ==> (1 1 0 0) & (1 0 1 1) ====> n = (1 0 0 0)

    ii) n = 8 i.e n > 0   so count = 2
    unset the first rightmost bit that is set by operation n&(n-1)
    n & (n-1) ==>  8 & 7 ==> (1 0 0 0) & (0 1 1 1) ====> n = (0 0 0 0)

    now n is 0 , so loop stops here

    count = 2
*/
