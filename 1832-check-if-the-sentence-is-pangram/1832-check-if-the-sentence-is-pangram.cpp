class Solution {
public:
    bool checkIfPangram(string sentence) {
        // frequency array to count occurrences of each letter in the alphabet
        vector<int>freq(26,0);

        // Count variable to track the unique characters encountered
        int count = 0;

        for(char &ch : sentence){
            int index = ch - 'a';
            
            // If the character is encountered for the first time, increment count
            // and mark it as present by updating its frequency count
            if( freq[index] == 0 ){
                count++;
                freq[index]++;
            }
        }

        // Check if all 26 unique characters have been encountered
        return count == 26;
    }
};