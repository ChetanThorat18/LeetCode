class Solution {
public:
    // Function to check if a character is a vowel
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    
    int maxVowels(string s, int k) {
        int n = s.length();
        int maxVowels = 0;

        // Iterate through the string to find substrings of length k
        for(int i = 0; i <= n - k; i++) {
            // Initialize the count of vowels in the current substring
            int vowelCount = 0;
            
            // Iterate through the current substring
            for(int j = i; j < i + k; j++) {
                // If the character at index j is a vowel, increment the vowel count
                if(isVowel(s[j])) {
                    vowelCount++;
                }
            }

            // Update the maximum number of vowels encountered so far
            maxVowels = max(maxVowels, vowelCount);
        }

        return maxVowels;
    }
};
