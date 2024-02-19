#include <vector>
#include <algorithm>

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort the greed factor array and cookie size array
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int m = g.size(); 
        int n = s.size(); 
        
        int i = 0, j = 0; 
        while (i < m && j < n) {
            // If the current cookie size is sufficient for the current child
            if (s[j] >= g[i]) {
                i++; // Move to the next child
            }
            j++; // Move to the next cookie
        }

        return i; // Return the number of content children
    }
};
