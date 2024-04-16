class Solution {
public:
    bool isVowel(char ch){
        ch = tolower(ch);

        // Check if the character is a vowel
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    string sortVowels(string s) {
        string tmp;

        for(char &ch : s){
            // If the character is a vowel, add it to the temporary string
            if(isVowel(ch)){
                tmp.push_back(ch);
            }
        }

        // Sort the temporary string containing vowels(in Ascending order)
        sort(tmp.begin(), tmp.end());

        int j=0;

        for(int i=0; i<s.length(); i++){
            // If the character is a vowel, replace it with the sorted vowel
            if(isVowel(s[i])){
                s[i] = tmp[j];
                j++;
            }
        }

        // Return the modified string with sorted vowels
        return s;
    }
};
