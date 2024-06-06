class Solution {
public:
    // Function to fill frequency array for a given word
    void fillFrequencyArray(int freq[], string word){
        for(char &ch : word)
            freq[ch - 'a']++;
    }

    vector<string> commonChars(vector<string>& words) {
        int n = words.size();

        // Initialize an array to store the frequency of characters in the first word
        int firstWordCharFreq[26] = {0};

        // Fill the frequency array for the first word
        fillFrequencyArray(firstWordCharFreq , words[0]);

        // Iterate through each word starting from the second one
        for(int i=1; i<n; i++){
            // Temporary array to store the frequency of characters in the current word
            int temp[26] = {0};

            // Fill the frequency array for the current word
            fillFrequencyArray(temp , words[i]);

            // Update the frequency array of the first word with the minimum frequency of characters
            for(int j=0; j<26; j++){
                firstWordCharFreq[j] = min(firstWordCharFreq[j] , temp[j]);
            }
        }

        // Initialize a vector to store the common characters
        vector<string> result;

        // Add characters to the result vector based on their frequencies
        for(int i=0; i<26; i++){
            // Add characters with non-zero frequency to the result vector
            int cnt = firstWordCharFreq[i];
            while(cnt--){
                result.push_back(string(1 , i + 'a'));
            }
        }

        return result;
    }
};