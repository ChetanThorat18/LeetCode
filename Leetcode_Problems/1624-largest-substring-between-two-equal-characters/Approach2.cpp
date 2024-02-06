class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int maxLen = -1;
        // Use an unordered_map to store the last index where each character was seen.
        unordered_map<char, int> lastSeen;

       
        for (int i = 0; i < s.length(); i++) {
            // Check if the current character has been seen before.
            if (lastSeen.find(s[i]) != lastSeen.end()) {
                // Update maxLen with the length between the equal characters.
                maxLen = max(maxLen, i - lastSeen[s[i]] - 1);
            } else {
                // If the character is encountered for the first time, store its index.
                lastSeen[s[i]] = i;
            }
        }

        return maxLen;
    }
};
