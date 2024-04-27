class Solution {
public:
    int fib(int n) {
        // Approach1 : Recursion

        // Base cases: F(0) = 0, F(1) = 1
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;

        // Recursive step: F(n) = F(n-1) + F(n-2)
        return fib(n-1) + fib(n-2);
    }
};
