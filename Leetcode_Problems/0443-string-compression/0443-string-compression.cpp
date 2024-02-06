class Solution {
public:
    int compress(vector<char>& chars) {
       int n = chars.size();

        int writeIndex = 0;
        int readIndex = 0;

        while(readIndex < n){
            char current_char = chars[readIndex];
            int count = 0;

            // Count consecutive repeating characters
            while(readIndex < n && chars[readIndex] == current_char){
                readIndex++;
                count ++;
            }

            // Write the current character
            chars[writeIndex] = current_char;
            writeIndex++;
            
             // Write the count if greater than 1
            if (count > 1) {
                string countStr = to_string(count);
                for (char c : countStr) {
                    chars[writeIndex] = c;
                    writeIndex++;
                }
            } 
        }

        return writeIndex;
    }
};

/*
        // Write the current character
            chars[writeIndex] = current_char;
            writeIndex++;

        Eg- chars = ['a','a','a','a','a','a','a','b','b'];
*/