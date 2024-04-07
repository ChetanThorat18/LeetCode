class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int>stk; // Stack to keep track of '(' indices
        unordered_set<int>remove_idx; // Set to store indices of ')' that need to be removed

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                stk.push(i); // Push index of '(' onto the stack
            }
            else if(s[i] == ')') {
                if(!stk.empty()) {
                    stk.pop(); // If there's a matching '(' in the stack, pop it
                }
                else {
                    remove_idx.insert(i); // If no matching '(' found, mark this ')' for removal
                }
            }
        }

        // eg- s = " (l(e(etco)de "
        // If there are unmatched '(' left in the stack, mark them for removal
        while(!stk.empty()) {
            int index = stk.top();
            remove_idx.insert(index);
            stk.pop();
        }

        string result;

        // Construct the resulting string excluding characters marked for removal
        for(int i = 0; i < n; i++) {
            if(remove_idx.find(i) == remove_idx.end()) {
                result += s[i]; // Append characters not marked for removal to the result
            }
        }

        return result; 
    }
};
