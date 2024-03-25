class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i=n-1;
        // Skip trailing spaces from the end of the string
        while (s[i] == ' ' && i >= 0) {
            i--;
        }

        int length = 0; 

        // Calculate the length of the last word
        while (i >= 0 && s[i] != ' ') {
            // Increment length for each non-space character
            length++; 
            // Move to the previous character
            i--;  
        }

        return length;
        
    }
};
