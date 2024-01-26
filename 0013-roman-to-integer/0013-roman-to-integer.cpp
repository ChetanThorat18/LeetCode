#include <unordered_map>
#include <string>

class Solution {
public:
    int romanToInt(std::string s) {
        // Create a mapping of Roman numerals to integers
        std::unordered_map<char, int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            // If the current numeral is smaller than the next numeral, subtract it
            if (mp[s[i]] < mp[s[i + 1]]) {
                ans -= mp[s[i]];
            } else {
                // Otherwise, add the current numeral
                ans += mp[s[i]];
            }
        }
        return ans;
    }
};
