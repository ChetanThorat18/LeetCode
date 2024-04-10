class Solution {
public:
    string orderlyQueue(string s, int k) {
        /*
           If k > 1, we are able to put the characters in any order. In this
            case, we just sort them in ascending order and return the resulting string right away.

            If k = 1, we cannot change the order of the characters in the string. We can
            only move them to the end of the string, one by one. In this case, we return the
            "minimum" string out of all possible s.Length candidates.
        */

        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }

        // If k == 1, we need to find the lexicographically smallest string
        // that can be obtained by moving one character from the beginning to the end
        string result = s;

        // Iterate through each possible move, i.e., each possible substring
        for (int i = 1; i <= s.length() - 1; i++) {
            // Construct the string after moving the first i characters to the end
            string temp = s.substr(i) + s.substr(0, i);

            // Update the result to the lexicographically smallest string
            result = min(result, temp);
        }

        return result;
    }
};