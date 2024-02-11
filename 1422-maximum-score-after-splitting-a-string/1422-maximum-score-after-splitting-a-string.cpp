class Solution {
public:
    int maxScore(string s) {
        // Approach 3: Single Pass
        int n = s.length();
        int result = INT_MIN; 


        int left_ones = 0; 
        int left_zeros = 0; 

       
        for(int i=0; i<n-1; i++){
            if(s[i] == '1'){
                left_ones++; 
            } else {
                left_zeros++;
            }

            // Calculate the score for the current split
            int currScore = left_zeros - left_ones;

            result = max(result , currScore);
        }

        // Check Last character
        if(s[n-1] == '1')
            left_ones++;

        return result + left_ones; // At this point , left_ones ==> total_ones
    }
};

/*
    Given : 
    Score = Left_Zeros + Right_Ones .......[1]
    ==> 
    Total_Ones = Left_Ones + Right_Ones

    Right_Ones = Total_Ones - Left_Ones;
    Put in [1]

    Score = Left_Zeros +  Total_Ones - Left_Ones;

    Score = (Left_Zeros - Left_Ones) + Total_Ones

    Here , Total_Ones is const , so we will add it in result at end
*/