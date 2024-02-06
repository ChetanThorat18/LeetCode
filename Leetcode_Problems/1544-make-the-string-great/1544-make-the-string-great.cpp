class Solution {
public:
    string makeGood(string s) {
        string result = "";

        for(char &ch : s){
            // Check if 'result' is not empty and 
            // the current character (ch) cancels the last character in result 
            // i.e same alphabet but either Small x Capital or Capital x Small pair
            if( !result.empty() &&  ( result.back() + 32 == ch || result.back() - 32 == ch )   ){
                // Remove the last character from 'result'
                result.pop_back();
            }else{
                // Append the current character to 'result'
                result.push_back(ch);
            }
        }

        return result;
    }
};