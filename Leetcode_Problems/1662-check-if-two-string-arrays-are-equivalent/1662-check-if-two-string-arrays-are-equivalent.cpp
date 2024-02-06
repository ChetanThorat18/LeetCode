class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int w1 = 0, i = 0; // indices for word1
        int w2 = 0, j = 0; // indices for word2

        while (w1 < word1.size() && w2 < word2.size()) {

            // Compare characters in the current words
            if (word1[w1][i] != word2[w2][j]) {
                return false;
            }

            // Move to the next character in the current word
            i++;
            j++;

            // Move to the next word if we reach the end of the current word
            if (i == word1[w1].length()) {
                i = 0;
                w1++;
            }
            if (j == word2[w2].length()) {
                j = 0;
                w2++;
            }
        }

        // Check if both arrays are exhausted
        return w1 == word1.size() && w2 == word2.size();
    }
};