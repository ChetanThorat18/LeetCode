class Solution {
public:
    int lengthOfLastWord(string s) {
        // Approach 2 : Using STL

        // Find First non-space character from end
        int last_non_space = s.find_last_not_of(' ');

        // Erase all trailing spaces from last_non_space onwards (if any) 
        s.erase( last_non_space + 1 );

        // After erasing trailing spaces , find first space character position from end 
        int last_space_pos = s.find_last_of(' ');

        // If there is only word left , then last_space_pos will be npos(i.e no position )
        // eg "abab"   s.find_last_of(' ') will return npos , return length of string in this case

        return last_space_pos == string::npos  ?  s.length()  :  s.length() - 1 - last_space_pos;
    } 
};
