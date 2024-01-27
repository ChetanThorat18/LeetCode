class Solution {
public:
    char findTheDifference(string s, string t) {
        int ASCII_Sum1 = 0;
        for(int i=0;i<s.size();i++){
            ASCII_Sum1 = ASCII_Sum1 + s[i];
        }
        int ASCII_Sum2 = 0;
        for(int i=0;i<t.size();i++){
            ASCII_Sum2 = ASCII_Sum2 + t[i];
        }

        return ASCII_Sum2 - ASCII_Sum1;
    }
};
