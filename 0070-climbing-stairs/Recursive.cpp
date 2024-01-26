//  TLE : Time Limit Exceeded

class Solution {
public:
    // Recursive function to calculate the number of ways to climb stairs
    int climbStairs(int n) {
        // Base cases: If n is 0 or 1, there is only one way to climb (no steps or one step)
        if (n == 0 || n == 1) {
            return 1;
        }

        // Recursive calls to calculate the number of ways for n-1 and n-2 steps
        // Summing up the results gives the total number of ways for n steps
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};
