class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i=n-1;
        while(s[i]==' '&& i>=0){
            i--;
        }
        int length = 0;
        while(i>=0 && s[i]!=' ' ){
            length++;
            i--;
        }

        return length;
        
    }
};