class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>stk;

        for(int i=0; i<s.size();i++){
             // If the stack is empty or the current character is different from the top of the stack
            if(stk.empty() || stk.top() != s[i]){
                // Push the current character onto the stack
                stk.push(s[i]);
            }
            else{
                // If the current character is the same as the top of the stack, pop from the stack
               stk.pop(); 
            }
        }

        string result = "";
        while(!stk.empty()){
            result += stk.top();
            stk.pop();
        }
    
        reverse(result.begin(),result.end());
        return result;
    }
};