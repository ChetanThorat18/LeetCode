class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // Approach 2 : O(1) space
        int i = s.length() - 1;
        int j = t.length() - 1;

        int backspacesS = 0;
        int backspacesT = 0;
        
        while(i >= 0 || j >= 0){
            
            // Process string s
            while(i >= 0){
                // If a backspace is encountered, increment the backspace count
                if(s[i] == '#'){
                    backspacesS++;
                }
                // If there are remaining backspaces, decrement the count
                else if(backspacesS > 0){
                    backspacesS--;
                }
                // If no more backspaces remain, break out of the loop
                else{
                    break;
                }
                
                // Move to the previous character in string s
                i--;
            }

            // Process string t (similar logic as above)
            while(j >= 0){
                if(t[j] == '#'){
                    backspacesT++;
                }
                else if(backspacesT > 0){
                    backspacesT--;
                }
                else{
                    break;
                }
                j--;
            }

            // If both pointers reach the beginning and all characters encountered are equal, return true
            if (i < 0 && j < 0) {
                return true;
            }

            // If the current characters are not equal or one pointer reaches the beginning while the other doesn't, return false
            if (i < 0 || j < 0 || s[i] != t[j]) {
                return false;
            }

            // Move both pointers to the left
            i--;
            j--;
        }

        // Both pointers reached the beginning and all characters encountered are equal
        return true; 
    }
};
