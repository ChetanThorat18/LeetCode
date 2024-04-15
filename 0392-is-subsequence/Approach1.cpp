class Solution {
public:
    bool isSubsequence(string s, string t) {
        // Approach 1 
        int m = s.length();
        int n = t.length();

        int i=0,j=0;

        while(i<m && j<n){
            // If the current characters of both strings match
            if(s[i] == t[j]){
                // Move to the next character in string s
                i++;
            }

            // Move to the next character in string t
            j++;
        }

        // If all characters of s have been found in t in order
        // i.e., i has reached the length of s
        // then return true, else return false
        return i == m;
    }
};
