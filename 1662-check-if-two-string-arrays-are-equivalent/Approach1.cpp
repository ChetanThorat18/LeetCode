class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1 = "";
        string str2 = "";

        // Concatenate elements in word1
        for(string &word : word1){
            str1 += word;
        }
        // Concatenate elements in word2
        for(string &word : word2){
            str2 += word;
        }
        // Compare the concatenated strings
        return str1 == str2;
    }
};
