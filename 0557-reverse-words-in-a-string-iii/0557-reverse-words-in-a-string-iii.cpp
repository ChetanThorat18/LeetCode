class Solution {
public:
    string reverseWords(string s) {
        int startPointer=0, endPointer =0;
        while(endPointer <= s.length()){
            // word will end at space or at end of string
            if(endPointer == s.length() || s[endPointer] == ' '){
                // reverse that word
                int left = startPointer;
                int right = endPointer-1;
                while(left < right){
                    char tmp = s[left];
                    s[left] = s[right];
                    s[right] = tmp;
                    left++;
                    right--;
                }
                startPointer = endPointer + 1;
                endPointer = startPointer;
            }
            endPointer++;
        }
        return s;
    }
};