class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Create an unordered map to store groups of anagrams
        unordered_map<string, vector<string>> mp;

        
        for (string str : strs) {
            // Sort the characters of the current string to identify its anagram group
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());

            // Add the original string to its corresponding anagram group in the map
            mp[sortedStr].push_back(str);
        }

        // Create a result vector to store the grouped anagrams
        vector<vector<string>> result;

        // Iterate through each group in the map and add it to the result vector
        for (auto& group : mp) {
            result.push_back(group.second);
        }

       
        return result;
    }
};
