class Solution {
public:
    int numberOfMatches(int n) {
        int noOfMatches = 0;
        // While Only one team is left(winner)
        while(n > 1){
            // If the current number of teams is even, A total of n / 2 matches are played,   and n / 2 teams advance to the next round.
            if( n%2 == 0){
                noOfMatches += n/2;
                n = n/2;
            }
            // If the current number of teams is odd, one team randomly advances in the tournament, and the rest gets paired. A total of (n - 1) / 2 matches are played, and (n - 1) / 2 + 1 teams advance to the next round.
            else{
                noOfMatches += (n-1)/2;
                n = (n-1)/ 2 + 1;
            }
        }

        return noOfMatches;
    }
};
