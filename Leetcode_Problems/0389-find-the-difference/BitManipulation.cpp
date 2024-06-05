class Solution {
public:
    char findTheDifference(string s, string t) {
        // Approach : Bit-Manipulation

        char result = t[t.length()-1];

        for(int i=0; i<s.length(); i++){
            result = result ^ s[i] ^ t[i];
        }

        return result;
    }
};

