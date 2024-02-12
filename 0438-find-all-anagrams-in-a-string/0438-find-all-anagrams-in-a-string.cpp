class Solution {
public:
    // Function to check if all elements in the frequency array are zero
    bool isAllZero(vector<int>& freq) {
        for(int &idx : freq) {
            if(idx != 0)
                return false; 
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        vector<int> freq(26, 0); 

        // Calculate frequency array for pattern string p
        for(char ch : p) {
            freq[ch - 'a']++;
        }

        int i = 0, j = 0; 
        vector<int> result; 
        int size = p.length(); 


        // Sliding window approach
        while(j < n) {
            freq[s[j] - 'a']--; // Decrement frequency of character at jth position

            // If the window size is equal to size of p
            if(j - i + 1 == size) {
                // If all elements in the frequency array are zero, it's an anagram
                if(isAllZero(freq)) {
                    result.push_back(i); // Add starting index of anagram to result
                }

                freq[s[i] - 'a']++; // Restore frequency of character at ith position
                i++; // Move left pointer to slide the window
            }

            j++; // Move right pointer to slide the window
        }

        return result; 
    }
};
