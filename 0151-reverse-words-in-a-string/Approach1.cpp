class Solution {
public:
    string reverseWords(string s) {
        // Use stringstream to break the input string into words
        stringstream ss(s);
        string word;
        vector<string> words;

        // Extract words from the stringstream
        while (ss >> word) {
            words.push_back(word);
        }

        // Reverse the order of words in the vector
        reverse(words.begin(), words.end());

        // Construct the result string by concatenating the words
        string result;
        for (int i = 0; i < words.size(); i++) {
            result += words[i];
            // Add a space between words, but not after the last word
            if (i != words.size() - 1) {
                result += " ";
            }
        }

        return result;
    }
};
