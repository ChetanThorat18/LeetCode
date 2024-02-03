class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        // Check if the lengths of both words are equal
        if (n1 != n2)
            return false;

        // Initialize frequency arrays for both words
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        // Count character frequencies for each word
        for (int i = 0; i < n1; i++) {
            char char1 = word1[i];
            char char2 = word2[i];

            int idx1 = char1 - 'a';
            int idx2 = char2 - 'a';

            freq1[idx1]++;
            freq2[idx2]++;
        }

        // Check if characters in both words are the same(not necessarily frequency)
        for (int i = 0; i < 26; i++) {
            // Characters in both words should either be present or absent

            if (freq1[i] == 0 && freq2[i] == 0)
                continue;
            if (freq1[i] != 0 && freq2[i] != 0)
                continue;

            return false;
        }

        // Sort frequency arrays and check if they are equal
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());

        return freq1 == freq2;
    }
};


/*
    Two words are considered close if:
    1. They have the same length.
    2. They have the same set of characters.
    3. They exhibit the same frequency pattern.

    Example: 
    word1 = "abaccc" and word2 = "abbbcc"

    Frequency pattern in word1: b = 1, a = 2, c = 3
    Frequency pattern in word2: a = 1, c = 2, b = 3

    Here, the frequency patterns are the same, allowing for character swaps between the two words.
*/


