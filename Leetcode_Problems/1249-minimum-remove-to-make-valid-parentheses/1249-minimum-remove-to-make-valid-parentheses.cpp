class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();

        string result = "";

        // Pass 1 : Get rid of extra closing brackets(if any) in given string

        int openBrackets = 0;
        for (int i = 0; i < n; i++) {
            // If the character is a lowercase English letter
            // Add it to the result string
            if (s[i] >= 'a' && s[i] <= 'z') {
                result.push_back(s[i]);
            }
            // If the character is an opening parenthesis
            // Increment the count of open brackets
            // Add it to the result string
            else if (s[i] == '(') {
                openBrackets++;
                result.push_back(s[i]);
            }
            // If the character is a closing parenthesis and there are unmatched
            // open brackets Decrement the count of open brackets to match this
            // closing parenthesis Add it to the result string
            else if (s[i] == ')' && openBrackets > 0) {
                openBrackets--;
                result.push_back(s[i]);
            }
        }

        // Initialize an empty string to store the final result
        string final_result = "";

         // Pass 2 : Get rid of extra opening brackets(if any) in result string of pass1

        int closeBrackets = 0;
        // Iterate through the intermediate result string in reverse order
        for (int i = result.length() - 1; i >= 0; i--) {
            // If the character is a lowercase English letter
            // Add it to the beginning of the final result string
            if (result[i] >= 'a' && result[i] <= 'z') {
                final_result.push_back(result[i]);
            }
            // If the character is a closing parenthesis
            // Increment the count of close brackets
            // Add it to the beginning of the final result string
            else if (result[i] == ')') {
                closeBrackets++;
                final_result.push_back(result[i]);
            }
            // If the character is an opening parenthesis and there are
            // unmatched close brackets Decrement the count of close brackets to
            // match this opening parenthesis Add it to the beginning of the
            // final result string
            else if (result[i] == '(' && closeBrackets > 0) {

                closeBrackets--;
                final_result.push_back(result[i]);
            }
        }

        reverse(final_result.begin(),final_result.end());
        return final_result;
    }
};
