class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // two maps to store mappings from s to t and from t to s
        unordered_map<char, char> s_to_t_mapping;
        unordered_map<char, char> t_to_s_mapping;

        // Iterate through each character in strings s and t
        for (int i = 0; i < s.length(); ++i) {
            // Get the current characters from strings s and t
            char char_s = s[i];
            char char_t = t[i];

            // Check if the current character from s has been mapped to a character in t before
            if (s_to_t_mapping.find(char_s) != s_to_t_mapping.end()) {
                // If it has been mapped before, check if the previous mapping is consistent
                if (s_to_t_mapping[char_s] != char_t)
                    return false; // Return false if the mapping is inconsistent
            } else {
                // If the current character from s has not been mapped before, add it to the mapping
                s_to_t_mapping[char_s] = char_t;
            }
            

            // Check if the current character from t has been mapped to a character in s before
            if (t_to_s_mapping.find(char_t) != t_to_s_mapping.end()) {
                // If it has been mapped before, check if the previous mapping is consistent
                if (t_to_s_mapping[char_t] != char_s)
                    return false; // Return false if the mapping is inconsistent
            } else {
                // If the current character from t has not been mapped before, add it to the mapping
                t_to_s_mapping[char_t] = char_s;
            }
        }

        return true;
    }
};

/*
    Reason for using two maps : 
        If We use only one map , it will not handle case of two characters getting mapped to same character.
        Eg- s = "badc"
            t = "baba"
*/
