class Solution {
public:
        // Brute Force 
        // Generate all possible substrings 
        //(Nested loops i.e Outer loop to pick starting character and inner loop to explore all substrings starting from that character) 
        // Check if it has repeating characters 
        // if not then record max length for each valid string

    bool isValid(string s,int start,int end){
        unordered_set<char>charSet;
        for(int i=start; i<= end ; i++ ){
            if(charSet.find(s[i]) != charSet.end()){
                return false;
            }
            charSet.insert(s[i]);
        }
        return true;
    }

    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        for(int i=0; i<s.length(); i++){
            for(int j=i ; j<s.length() ; j++){
                //check if current substring is valid or not
                if( isValid(s,i,j) ){
                    maxLength = max(maxLength , j-i+1); // plus one because index starts from 0, we need length
                }
            }
        }

        return maxLength;
    }
};
