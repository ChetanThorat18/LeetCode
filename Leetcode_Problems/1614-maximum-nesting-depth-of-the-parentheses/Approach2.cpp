class Solution {
public:
    int maxDepth(string s) {
        // Approach: O(1) Space

        // Variable to keep track of open parentheses(nesting depth)
        int openBrackets = 0;

        // Variable to store the maximum depth encountered
        int result = 0;

        for(char &ch : s) {
            // If the character is an open parenthesis, increment the count of open brackets
            if(ch == '(') {
                openBrackets++;
            }
            // If the character is a closing parenthesis, decrement the count of open brackets
            else if(ch == ')') {
                openBrackets--;
            }

            // Update the result with the maximum depth encountered so far
            result = max(result , openBrackets);
        }

        return result;
    }
};
