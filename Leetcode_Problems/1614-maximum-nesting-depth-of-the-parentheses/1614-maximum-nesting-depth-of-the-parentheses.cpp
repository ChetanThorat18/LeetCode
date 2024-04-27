class Solution {
public:
    int maxDepth(string s) {
        // Approach: Using a stack to keep track of open parentheses

        // Create a stack to store open parentheses
        stack<char> stk;

        int result = 0;

        for(char &ch : s) {
            // If the character is an open parenthesis, push it onto the stack
            if(ch == '(') {
                stk.push(ch);
            }
            // If the character is a closing parenthesis, pop from the stack
            // (assuming there is a matching open parenthesis)
            else if(ch == ')') {
                stk.pop();
            }

            // Update the result with the maximum depth encountered so far
            result = max(result , (int)stk.size());
        }

        return result;
    }
};
