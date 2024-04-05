class Solution {
public:

    // Helper function to check if all characters in the word fall within the specified range
    bool isValid(string word, char start, char end) {
        for(char &ch : word) {
            // If any character is outside the specified range, return false
            if(ch < start || ch > end) {
                return false;
            }
        }
        // If all characters are within the specified range, return true
        return true;
    }

    bool detectCapitalUse(string word) {

        // Check if all letters are capitals or all are lowercase
        if (isValid(word, 'A', 'Z') || isValid(word, 'a', 'z') ||
            // Check if only the first letter is capital and the rest are lowercase
            isValid(word.substr(1), 'a', 'z')) {


            return true;
        }

        return false;
    }
};
