class Solution {
public:
    string largestGoodInteger(string num) {
        char maxChar = ' ';
        for(int i=0;i<num.length()-2;i++){
            if(num[i] == num[i+1] && num[i] == num[i+2]){
                maxChar = max(maxChar,num[i]);
            }
        }

        return maxChar == ' ' ? "" : string(3,maxChar);
    }
};