#include <vector>
#include <algorithm>

class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans = "";

        // Sort the array of strings lexicographically
        sort(v.begin(), v.end());

        // Get the first and last strings in the sorted array
        string first = v[0];
        string last = v[v.size() - 1];

        // Iterate through the characters of the first and last strings
        for (int i = 0; i < min(first.size(), last.size()); i++) {
            // If the characters are equal, append the character to the common prefix
            if (first[i] == last[i]) {
                ans += first[i];
            } else {
                // If the characters are not equal, stop the iteration as the common prefix ends
                return ans;
            }
        }

        // Return the longest common prefix found
        return ans;
    }
};
