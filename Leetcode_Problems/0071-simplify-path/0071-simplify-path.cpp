class Solution {
public:
    string simplifyPath(string path) {
        // Initialize an empty string to store each token
        string token = "";

        // Create a stringstream to process the input path
        stringstream ss(path);

        // Create a stack to store the directories
        stack<string> stk;

        // Iterate through each token separated by delemeter '/'
        while (getline(ss, token, '/')) {
            // Ignore empty tokens and current directory '.'
            if (token == "" || token == ".") {
                continue;
            }

            // If the token is not '..', push it to the stack
            if (token != "..") {
                stk.push(token);
            }
            // If the token is '..', pop the top directory from the stack if it's not empty
            else if (!stk.empty()) {
                stk.pop();
            }
        }

        // If the stack is empty, return a single slash '/'
        if (stk.empty()) {
            return "/";
        }

        // Initialize an empty string to store the result
        string result = "";

        // Construct the simplified canonical path by popping directories from the stack
        // and appending them to the result string
        while (!stk.empty()) {
            // Add the current directory to the result string
            result = "/" + stk.top() + result;
            // Pop the current directory from the stack
            stk.pop();
        }

        return result;
    }
};
