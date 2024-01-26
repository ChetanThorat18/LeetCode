#include <string>

class Solution {
public:
    
    string reverseOnlyLetters(string s) {
        int low = 0;  
        int high = s.size() - 1; 

        
        while (low < high) {
            // If both characters at low and high indices are letters, swap them
            if (isalpha(s[low]) && isalpha(s[high])) {
                swap(s[low], s[high]);
                low++;    
                high--;   
            } else if (!isalpha(s[low])) {
                low++;    // If character at low index is not a letter, move low pointer forward
            } else {
                high--;   // If character at high index is not a letter, move high pointer backward
            }
        }

        return s;  
    }
};
