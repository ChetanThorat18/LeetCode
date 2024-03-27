class Solution {
public:
    int firstUniqChar(string s) {
        int visited[26] = {0}; 
        for(int i = 1; i <= s.length(); i++) {
            char ch = s[i - 1]; 
            int idx = ch - 'a'; 

            if(visited[idx] == 0) {
                // If the character has not been visited before, store its position as negative index
                visited[idx] = -i;
            } else {
                // If the character has been visited before, store its position as positive index
                visited[idx] = i;
            }
        }

        int minPosition = INT_MAX; 

        // Iterate through the visited array to find the minimum position of unique characters(first unique ==> min index)
        for(int i = 0; i < 26; i++) {
            if(visited[i] < 0) {
                // If the character is unique, update the minimum position
                minPosition = min(minPosition , -visited[i]);
            }
        }

        return minPosition == INT_MAX ? -1 : minPosition - 1;
    }
};
