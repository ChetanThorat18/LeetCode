class Solution {
public:
    // Function to check if a character is a vowel
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int maxVowels(string s, int k) {
        // Sliding Window Approach

        int n = s.length(); 

        int maxVowels = INT_MIN; 
        int vowelCount = 0; 
        int i = 0, j = 0; 

        while (j < n) { 

            // If the character at index j is a vowel, increment the vowel count
            if (isVowel(s[j]))
                vowelCount++;

            // If the size of the current window is equal to k
            if (j - i + 1 == k) {
                // Update the maximum number of vowels encountered so far
                maxVowels = max(maxVowels, vowelCount);

                // If the character at index i is a vowel, decrement the vowel count
                // Since , It will be no more part of current Window
                if (isVowel(s[i]))
                    vowelCount--;

                // Move the left pointer forward to slide the window(shrink)
                i++;
            }

            // Move the right pointer forward to slide the window
            j++;
        }

        return maxVowels;
    }
};
