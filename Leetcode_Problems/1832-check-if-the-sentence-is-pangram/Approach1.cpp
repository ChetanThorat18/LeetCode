class Solution {
public:
    bool checkIfPangram(string sentence) {
        // frequency array to count occurrences of each letter in the alphabet
        vector<int>freq(26,0);

        for(char &ch : sentence){
            int index = ch - 'a';
            freq[index]++;
        }

        // Check if any character in the alphabet has a count of zero (not present)
        for(int &count : freq){
            if(count == 0)
                return false;
        }

        return true;
    }
};
