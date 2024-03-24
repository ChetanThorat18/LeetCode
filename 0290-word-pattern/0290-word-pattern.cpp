class Solution {
public:
    bool wordPattern(string pattern, string s) {
        // Initialize two unordered maps:
        // charToWordMap: Maps each character in the pattern to its corresponding word in string s.
        // wordToCharMap: Maps each word in string s to its corresponding character in the pattern.
        unordered_map<char, string> charToWordMap;
        unordered_map<string, char> wordToCharMap;

        // Split the string s into individual words
        stringstream ss(s);
        vector<string> words;
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        
        // If the number of characters in the pattern does not match the number of words in s, return false
        if(pattern.size() != words.size())
            return false;

        // Iterate through each character in the pattern
        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            string word = words[i];

            // Check if the current character is already mapped to a word
            if (charToWordMap.find(ch) != charToWordMap.end()) {
                // If yes, check if the mapped word matches the current word
                if (charToWordMap[ch] != words[i]) {
                    return false; // If not, return false
                }
            } else {
                // If not, map the current character to the current word
                charToWordMap[ch] = words[i];
            }

            // Check if the current word is already mapped to a character
            if (wordToCharMap.find(word) != wordToCharMap.end()) {
                // If yes, check if the mapped character matches the current character
                if (wordToCharMap[word] != ch) {
                    return false; // If not, return false
                }
            } else {
                // If not, map the current word to the current character
                wordToCharMap[word] = ch;
            }
        }

        // If all characters in the pattern and their corresponding words in s form a bijection, return true
        return true;
    }
};
