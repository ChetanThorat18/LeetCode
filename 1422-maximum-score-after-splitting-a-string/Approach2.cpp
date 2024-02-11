class Solution {
public:
    int maxScore(string s) {
        // Approach 2 : Two Pass
        int n = s.length();
        int result = INT_MIN; 

        // Count of total ones in the string
        int total_ones = 0; 
        for(int i=0; i<n; i++){
            if(s[i] == '1')
                total_ones++;
        }

        int left_ones = 0; // Count of ones in the left substring
        int left_zeros = 0; // Count of zeros in the left substring

       
        for(int i=0; i<n-1; i++){
            if(s[i] == '1'){
                left_ones++; 
            } else {
                left_zeros++;
            }

            // Calculate the number of ones in the right substring
            int right_ones = total_ones - left_ones;

            // Calculate the score for the current split
            int currScore = left_zeros + right_ones;

            result = max(result , currScore);
        }

        return result; 
    }
};
