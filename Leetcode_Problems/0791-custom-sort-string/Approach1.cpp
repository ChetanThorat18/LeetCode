class Solution {
public:
string customSortString(string order, string s) {
        int freq[26] = {0}; // Array to store frequency of characters in string s

        // Count the frequency of each character in string s
        for (char &ch : s) {
            freq[ch - 'a']++;
        }

        string result = ""; 

        // Iterate through each character in the 'order' string
        for (char &ch : order) {
            // Append the current character to the result string as per its frequency in s
            while (freq[ch - 'a'] > 0) {
                result.push_back(ch);
                freq[ch - 'a']--; 
            }
        }

        // Append any remaining characters from s that are not in the string 'order'
        for (char &ch : s) {
            if (freq[ch - 'a'] > 0) {
                result.push_back(ch);
            }
        }

        return result; 
    }
};

/*
    Time Complexity : O(n1 + n2)
    Space Complexity : O(1)
*/
