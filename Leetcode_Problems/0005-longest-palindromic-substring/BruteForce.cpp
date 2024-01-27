class Solution {
public:
    // Brute Force : Memory Limit Exceeded

 bool isPalindrome(string s,int start,int end){
    int i=start;
    int j=end;
    while(i<j){
        if(s[i] != s[j])
            return false;
        i++;
        j--;
    }       
    return true;   
 }

    string longestPalindrome(string s) {
        int maxLength = 0;
        string result="";
       for(int i=0;i<s.length();i++){
           for(int j=i;j<s.length();j++){
               if( isPalindrome(s,i,j) ){
                   if(maxLength < j-i+1){
                       maxLength = j-i+1;
                       result = "";
                       int start = i;
                       while(start <= j){
                           result += s[start++]; 
                       }
                   }
               }
           }
       }

       return result;
    }
};
