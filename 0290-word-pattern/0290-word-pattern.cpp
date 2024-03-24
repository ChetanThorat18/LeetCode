class Solution {
public:
    bool wordPattern(string pattern, string s) {

        unordered_map<char, string> charToWordMap;
        unordered_map<string, char> wordToCharMap;

        // Split the string s into individual words
        stringstream ss(s);
        vector<string> words;
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        
        if(pattern.size() != words.size())
            return false;

        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            string word = words[i];

            if (charToWordMap.find(ch) != charToWordMap.end()) {

                if (charToWordMap[ch] != words[i]) {
                    return false;
                }
            } else {
                charToWordMap[ch] = words[i];
            }

            if (wordToCharMap.find(word) != wordToCharMap.end()) {

                if (wordToCharMap[word] != ch) {
                    return false;
                }
            } else {
                wordToCharMap[word] = ch;
            }
        }

        return true;
    }
};