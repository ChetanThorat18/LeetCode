class Solution {
public:
    bool isAnagram(string s, string t) {
        // Check if the lengths of strings s and t are different, if yes, they cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        int freqTable[256] = {0}; // Assuming ASCII characters (256 possible values)

        // Update frequency table for string s
        for (int i = 0; i < s.length(); i++) {
            freqTable[s[i]]++;
        }

        // Update frequency table for string t
        for (int i = 0; i < t.length(); i++) {
            freqTable[t[i]]--;
        }

        // Check if all frequencies in the table are zero, indicating both strings have the same character counts
        for (int i = 0; i < 256; i++) {
            if (freqTable[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
