class Solution {
public:
    // Helper Function to build the final string after processing backspaces
    string buildString(string &s){
        int n = s.length();

        string tmp = "";
        int i=0;
        while(i < n){
            // If the current character is not a backspace, add it to the temporary string
            if(s[i] != '#'){
                tmp.push_back(s[i]);
            }
            // If the current character is a backspace and the temporary string is not empty, remove the last character
            else if(tmp.length() > 0){
                tmp.pop_back();
            }

            i++;
        }

        return tmp;
    }

    bool backspaceCompare(string s, string t) {
        // Approach 1 : O(m+n) space
        // Build the final strings after processing backspaces
        string first = buildString(s);
        string second = buildString(t);

        // Compare the final strings and return true if they are equal, false otherwise
        return first == second;
    }
};
