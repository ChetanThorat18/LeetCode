class Solution {
public:
    string clearDigits(string s) {
        stack<char>stk;
        
        for(char &ch : s){
            if(ch >= 'a' && ch <= 'z'){
                stk.push(ch);
            }else{
                stk.pop();
            }
        }
        
        string result = "";
        
        while(!stk.empty()){
            result = stk.top() + result ;
            stk.pop();
        }
        
        return result;
    }
};
