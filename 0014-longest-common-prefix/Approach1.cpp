#include <vector>
#include <string>

class Solution {
public:
    // Helper function to find common prefix between two strings
    string common(string s1, string s2) {
        int n = min(s1.length(), s2.length());
        string res = "";
        for (int i = 0; i < n; i++) {
            if (s1[i] == s2[i]) {
                res = res + s1[i];
            } else {
                break;
            }
        }
        return res;
    }

    // Main function to find the longest common prefix among an array of strings
    string longestCommonPrefix(vector<string>& strs) {
        // Initialize the common prefix with the first word of the array
        string ans = strs[0];

        // Iterate through the remaining words in the array
        for (int i = 1; i < strs.size(); i++) {
            // Update the common prefix by finding the common part with the current word
            ans = common(ans, strs[i]);
        }

        // Return the final longest common prefix
        return ans;
    }
};
