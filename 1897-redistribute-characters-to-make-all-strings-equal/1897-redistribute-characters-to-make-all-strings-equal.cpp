
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        // Get the number of words
        int n = words.size();
        
        // Map to store character frequencies
        unordered_map<char,int> charFreq;

        // Count frequencies of characters in all words
        for(string &word : words){
            for(char &ch : word){
                charFreq[ch]++;
            }
        }

        // Check if frequencies are divisible by the number of words
        for(auto &itr : charFreq){
            int freq = itr.second;
            if(freq % n != 0){
                return false;
            }
        }

        
        return true;
    }
};

/*
    eg -  words = ["ab","a"]
    freq[a] = 2
    freq[b] = 1 

    1. freq[a] % 2 == 0 i.e it can be distributed equally among n words
    2. freq[b] % 2 != 0 i.e it can not be distributed equally among n words
*/
