class Solution {
public:
    int maxScore(string s) {
        // Initialize the maximum score to the count of '1's in the right substring
        int maxScore = count(s.begin() + 1 , s.end() , '1');

        // If the first character of the string is '0', increment the maximum score
        if(s[0] == '0'){
            maxScore++;
        } 

        int result = maxScore;

        for(int i=1; i<s.length()-1; i++){
            // If the current character is '0', increment the maximum score
            // Otherwise, decrement the maximum score
            if(s[i] == '0'){
                maxScore++;
            } else {
                maxScore--;
            }

            // Update the result with the maximum score encountered so far
            result = max(result , maxScore);
        }

        return result;
    }
};
