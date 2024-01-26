class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Omptimized O(n) sliding window approach
        int left=0,right=0;
        int maxLength = 0;

        unordered_set<char>charSet;

        while( right < s.length() ){
            // if not in charSet then insert and update maxLength
            if( charSet.find(s[right]) == charSet.end() ){
                charSet.insert(s[right]);
                maxLength = max( maxLength,right-left+1);
                right++;
            }
            else{
                // if already in charSet(i.e. repeating character)
                // remove character at position left and move left to right
                charSet.erase(s[left++]);
            }
            
        } 
        return maxLength;
    } 
};