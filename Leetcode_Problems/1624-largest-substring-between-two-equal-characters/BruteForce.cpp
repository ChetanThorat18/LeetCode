class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int maxLength = -1;

        // Iterate through each character as a potential left boundary.
        for (int left = 0; left < s.size(); left++) {

            // Iterate through characters to the right of the left boundary.
            for (int right = left + 1; right < s.size(); right++) {

                // Check if the characters at left and right indices are equal.
                if (s[left] == s[right]) {

                    // Update maxLength with the length between the equal characters.
                    maxLength = max(maxLength, right - left - 1);
                }
            }
        }
        
        return maxLength;
    }
};
