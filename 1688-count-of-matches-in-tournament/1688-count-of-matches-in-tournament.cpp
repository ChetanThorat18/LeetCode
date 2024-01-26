class Solution {
public:
    int numberOfMatches(int n) {
        // Total teams = n
        // Winner = 1
        // Eliminated teams = n-1

        // in each match , 1 team gets eliminated
        // So , for eliminating (n-1) teams , n-1 matches will be played 

        return n-1;
    }
};