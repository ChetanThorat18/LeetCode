class Solution {
public:
    bool isPowerOfTwo(int n) {
        if( n <= 0)
            return false;
        if(n == 1)
            return true;

        return (n % 2) == 0 && isPowerOfTwo(n/2); 
    }
};

/*
    Let n = 8

    - Check if n is divisible by 2 (i.e., n % 2 == 0):
     - 8 % 2 == 0, so the condition is true.
   - Call the function recursively with n/2:
     - isPowerOfTwo(8 / 2) = isPowerOfTwo(4)

   - Now, evaluate isPowerOfTwo(4):
     - Check if n is divisible by 2:
       - 4 % 2 == 0, so the condition is true.
     - Call the function recursively with n/2:
       - isPowerOfTwo(4 / 2) = isPowerOfTwo(2)

   - Now, evaluate isPowerOfTwo(2):
     - Check if n is divisible by 2:
       - 2 % 2 == 0, so the condition is true.
     - Call the function recursively with n/2:
       - isPowerOfTwo(2 / 2) = isPowerOfTwo(1)

   - Now, evaluate isPowerOfTwo(1):
     - n == 1, so return true.

*/
