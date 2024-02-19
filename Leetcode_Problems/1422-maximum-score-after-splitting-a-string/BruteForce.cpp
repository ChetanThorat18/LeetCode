
class Solution {
public:
    int maxScore(string s) {
        // Brute Force Approach : Splitiing And Counting at all indices
        int n = s.length();
        int result = INT_MIN;
        
        for(int i=0; i<n-1; i++){

            int zeros_count = 0;
            for(int j=0; j<=i; j++){
                if(s[j] == '0')
                    zeros_count++;
            }

            int ones_count = 0;
            for(int j=i+1; j<n; j++){
                if(s[j] == '1')
                    ones_count++;
            }

            result = max(result ,  zeros_count +  ones_count );
        }

        return result;
    }
};
