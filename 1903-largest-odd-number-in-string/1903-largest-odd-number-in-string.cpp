class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.length();

        // find odd digit from last and return string from starting to that index
        // eg-  "3542768"  => first odd digit from last is 7 => Largest odd number is 35427
        int i;
        for(i = n-1; i>=0 ; i--){
            if(  (num[i] - '0') % 2 != 0){
                break;
            }
        }

        return num.substr(0,i+1); // substr(startIndex, length)
    }
};