class Solution {
public:
    // Function to find the root of a word from the dictionary set
    string findRoot(string &word, unordered_set<string>& Set) {
        
        // Iterate over each possible prefix length of the word
        for (int len = 1; len <= word.length(); len++) {
            // Extract the prefix (potential root) of the current length
            string root = word.substr(0, len);
            // Check if this prefix is a valid root in the dictionary set
            if (Set.count(root))
                return root; // If found, return the root
        }
        return word; // If no root is found, return the original word
    }

    string replaceWords(vector<string>& dictionary, string sentence) {

        // Create an unordered set from the dictionary for fast lookup
        unordered_set<string> Set(dictionary.begin(), dictionary.end());

        // Use a stringstream to split the sentence into words
        stringstream ss(sentence);
        string word;

        string result;

        // Iterate over each word in the sentence
        while (getline(ss, word, ' ')) {
            // Find the root for the current word and append it to the result
            result += findRoot(word, Set) + " ";
        }

        // Remove the trailing space from the result string
        result.pop_back();

        return result; 
    }
};
