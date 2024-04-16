class Solution {
public:
    bool isVowel(char ch){
        ch = tolower(ch);
        // Check if the character is a vowel
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    string sortVowels(string s) {
        // Map to store the count of each vowel in the string
        unordered_map<char,int> mp;

        // Count the occurrences of each vowel in the string
        for(char &ch : s){
            if(isVowel(ch)){
                mp[ch]++;
            }
        }

        // Define the sorted order of vowels
        string sortedOrder = "AEIOUaeiou";
        int j = 0;

        for(int i = 0; i < s.length(); i++){
            // If current character is vowel
            if(isVowel(s[i])){
                // Get the current sorted vowel
                char currSortedVowel = sortedOrder[j];

                // Move to the next sorted vowel until its count is greater than 0
                while(mp[currSortedVowel] == 0){
                    j++;
                    currSortedVowel = sortedOrder[j];
                }

                // Replace the current vowel with the sorted vowel
                s[i] = currSortedVowel;
                // Decrement the count of the sorted vowel
                mp[currSortedVowel]--;
            }
        }

        return s;
    }
};
