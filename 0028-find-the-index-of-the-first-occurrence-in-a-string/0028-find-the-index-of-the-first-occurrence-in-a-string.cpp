class Solution {
public:
    int strStr(string haystack, string needle) {
        // Check if the needle is an empty string
        if (needle.length() == 0)
            return -1;

        // Iterate through each character of the haystack
        for (int i = 0; i < haystack.length(); i++) {
            bool match = true;

            // Check if the substring starting from index i in haystack matches needle
            for (int j = 0; j < needle.length(); j++) {
                if (haystack[i + j] != needle[j]) {
                    match = false;
                    break;
                }
            }

            // If a match is found, return the starting index
            if (match) {
                return i;
            }
        }

        // If no match is found, return -1
        return -1;
    }
};
