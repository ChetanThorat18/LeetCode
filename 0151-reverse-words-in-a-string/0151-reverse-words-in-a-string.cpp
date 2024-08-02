class Solution {
public:
    string reverseWords(string s) {
        // Reverse the entire string
        reverse(s.begin(), s.end());

        int i = 0;        // Pointer for iterating over the string
        int left = 0;     // Start of the current word
        int right = 0;    // End of the current word
        int n = s.length();  

        while (i < n) {
            // Move characters of the current word to the correct position
            // i.e replacing extra spaces with actual word characters
            while (i < n && s[i] != ' ') {
                s[right++] = s[i++];
            }

            // If a word was found, reverse it
            if (left < right) {
                reverse(s.begin() + left, s.begin() + right);

                // Add a space after the word if it's not the last word
                s[right] = ' ';
                right++;
                left = right;
            }

            // Skip spaces
            i++;
        }

        // Remove the trailing space if there is any
        s = s.substr(0, right - 1);

        return s;
    }
};
