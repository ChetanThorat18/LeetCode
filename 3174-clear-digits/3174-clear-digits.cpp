
class Solution {
public:
    string clearDigits(string s) {
        // Create an empty string to store the result
        string result = "";
        
        for(char &ch : s) {
            // Check if the character is a non-digit character (lowercase letter)
            if(ch >= 'a' && ch <= 'z') {
                // If it's a non-digit, add it to the result string
                result.push_back(ch);
            } else {
                // If it's a digit, remove the last non-digit character from the result    
                    result.pop_back();
            }
        }
        
        // Return the final result string after all operations
        return result;
    }
};