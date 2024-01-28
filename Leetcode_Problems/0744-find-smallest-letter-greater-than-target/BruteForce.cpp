class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // Brute Force

        for(char letter : letters){
            if(letter > target)
                return letter;
        }

        return letters[0];
    }
};
