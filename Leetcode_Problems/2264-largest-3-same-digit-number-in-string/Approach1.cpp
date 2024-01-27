class Solution {
public:
    string largestGoodInteger(string num) {
        // start cheking from third charater if it is same as previous two charaters 
       char maxChar = ' ';
       int n = num.length();
       for( int i = 2; i<n ; i++){
           if( num[i] == num[i-1]  && num[i] == num[i-2]){
               maxChar = max(maxChar , num[i]);
           }
       }

       if(maxChar == ' ')
        return "";

        return string(3,maxChar) ; // eg - maxChar = 7 , it returns  ""777""


    }
};
