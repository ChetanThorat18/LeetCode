class Solution {
public:
    bool isSubsequence(string s, string t) {
        // Approach 2: Follow Up

        int m = s.length(); // Length of string s
        int n = t.length(); // Length of string t

        // Create a map to store character indices in t
        unordered_map<char, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[t[i]].push_back(i); // Store the index of each character in t
        }

        int prev_idx = -1; // Initialize the previous index found to -1
        for (int i = 0; i < m; i++) {
            char curr_char = s[i]; 

            // If the current character doesn't exist in t, return false
            if (mp.find(curr_char) == mp.end())
                return false;

            vector<int> indices = mp[curr_char]; // Get the indices of the current character in t

            // Find the first index greater than the previous index found
            // upper_bound ==> finds first greater using binary search
            auto idx = upper_bound(indices.begin(), indices.end(), prev_idx);

            // If no such index exists, return false
            if (idx == indices.end())
                return false;

            prev_idx = *idx; // Update the previous index found
        }

        // If all characters in s are found in t in order, return true
        return true;
    }
};