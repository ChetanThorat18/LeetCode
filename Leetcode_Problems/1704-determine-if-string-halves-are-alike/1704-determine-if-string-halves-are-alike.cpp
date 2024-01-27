class Solution {
public:
    bool halvesAreAlike(string s) {
        // Approach : If we encounter Vowel in first half increment count of vowels and if we encounter vowel on right half decrement counter
        // At the end , if counter is zero then return true else return false

        unordered_set<char>vowelSet{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        int i=0,j=s.length()-1;
        int noOfVowels = 0;
        while(i < j){
            if( vowelSet.count(s[i]) > 0 ){
                noOfVowels++;
                
            }
             if( vowelSet.count(s[j]) > 0  ){
                noOfVowels--;
            }
            i++;
            j--;
        }

        return noOfVowels == 0;
    }
};