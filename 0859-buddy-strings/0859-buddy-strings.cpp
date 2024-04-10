class Solution {
public:
    // Function to check if there are duplicate characters in the string
    bool checkFreq(string &s) {
        int freq[26] = {0};

        for(char &ch : s) {
            freq[ch - 'a']++; // Incrementing the frequency of the character

            // If the frequency becomes greater than 1, there are duplicate characters
            if(freq[ch - 'a'] > 1)
                return true;
        }

        return false; // No duplicate characters found
    }

    bool buddyStrings(string s, string goal) {
        if(s.length() != goal.length()) {
            return false;
        }

        // If s and goal are equal, check if there are duplicate characters
        // If there is at least one duplicate character , we can swap it(which is mandatory as per problem) , while s will still  remain same
        // eg ->  s = "abcda" goal = "abcda"
        // Here , s == goal , and character 'a' is duplicate , after swapping 'a' , it still gives same string equal to goal
        // But if there is no duplicate character , we cannot make s == goal by swapping
        // Eg -  s = "abcde" goal = "abcde" 
        if(s == goal) {
            return checkFreq(s);
        }

        // If s and goal are not equal, store indices where characters differs in this strings
        int n = s.length();
        vector<int> diffIndices;

        for(int i = 0; i < n; i++) {
            // If characters at current indices are different, store the index
            if(s[i] != goal[i]) {
                diffIndices.push_back(i);
            }
        }

        // If there are not exactly two differences, return false
        // Because , if there are exactly two differences , then only we can make s == goal by swapping
        if(diffIndices.size() != 2)
            return false;

        // Swap characters at the differing indices in s
        swap(s[diffIndices[0]], s[diffIndices[1]]);

        // Return true if s becomes equal to goal after swapping, otherwise false
        return s == goal;
    }
};
