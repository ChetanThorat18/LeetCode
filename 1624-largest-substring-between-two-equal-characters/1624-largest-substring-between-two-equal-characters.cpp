class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> v1(26, -1);  // v1 stores the first occurrence index
        vector<int> v2(26, -1);  // v2 stores the last occurrence index
        int ans = -1;  

        for (int i = 0; i < s.size(); ++i) {
            int temp = s[i] - 'a';  // Convert character to index (0 to 25) for lowercase letters.

            // Check if the character has been seen before.
            if (v1[temp] == -1) {
                // If not, store the first occurrence index.
                v1[temp] = i;
            } else {
                // If the character is encountered again, store the last occurrence index.
                v2[temp] = i;
                // Update ans with the length between the equal characters.
                ans = max(ans, v2[temp] - v1[temp] - 1);
            }
        }

        return ans;
    }
};
