class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int result = 0;

        // count frequency of each character in chars array
        vector<int>charFreq(26,0);
        for(char &ch : chars){
            charFreq[ch-'a'] ++; 
        }

        // check for each word 
        for(string &word : words){
            
            // count frequency of all characters of each word
            vector<int>WordCharFreq(26,0);
            for(char &ch : word){
                WordCharFreq[ch-'a']++;
            }

            // now check if freq of each character in word is not greater than original chars frequency
            bool flag = true;
            for(int i=0;i<26;i++){
                if(WordCharFreq[i] > charFreq[i]){
                    flag = false;
                    break;
                }
            }
            
            // if word is valid then update result
            if(flag == true)
                result = result + word.length();
        }
        return result;
    }
};