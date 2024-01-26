class Solution {
public:
    string longestPalindrome(string s) {
        // Slightly Optimized O(n^2)
        // Approach 2: Expand Around Center
        /*
            => we will iterate over the string and for every character we will expand around its center.
            => For odd length palindrome, we will consider the current character as the center and expand around it.
            => For even length palindrome, we will consider the current character and the next character as the center and expand around it.
            => We will keep track of the maximum length and the maximum substring.
        */
        // Time complexity : O(n^2). Since expanding a palindrome around its center could take O(n) time, the overall complexity is O(n^2).
        string res = "";
        int resStart = 0;
        int resLen = 0;

        for (int i = 0; i < s.length(); i++) {
            // Odd length
            int left = i, right = i;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                if (right - left + 1 > resLen) {
                    resStart = left;
                    resLen = right - left + 1;
                }
                left--;
                right++;
            }

            // Even length
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                if (right - left + 1 > resLen) {
                    resStart = left;
                    resLen = right - left + 1;
                }
                left--;
                right++;
            }
        }

        // Use substr only once at the end
        res = s.substr(resStart, resLen);
        return res;
    }
};