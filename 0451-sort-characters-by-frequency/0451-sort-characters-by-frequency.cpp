class Solution {
public:
    // Comparator function to sort characters based on their frequency
    static bool myComparator(pair<char, int>& p1, pair<char, int>& p2) {
        return p1.second > p2.second; // Sort in decreasing order of frequency
    }

    string frequencySort(string s) {
        vector<pair<char, int>> freqArray(123); // Array to store frequency of each character

        // Count the frequency of each character in the input string
        for (char& ch : s) {
            int freq = freqArray[ch].second;
            freqArray[ch] = {ch, freq + 1}; // Increment the frequency
        }

        // Sort characters based on their frequency using custom comparator
        sort(freqArray.begin(), freqArray.end(), myComparator);

        string result = ""; 

        // Iterate through the sorted frequency array and append characters to the result string
        for (int i = 0; i < 123; i++) {
            if (freqArray[i].second > 0) { // If the character has a non-zero frequency
                int freq = freqArray[i].second;
                char ch = freqArray[i].first;
                string tmp = string(freq, ch); // Create a string with repeated characters
                result += tmp; // Append to the result string
            }
        }

        return result; 
    }
};
