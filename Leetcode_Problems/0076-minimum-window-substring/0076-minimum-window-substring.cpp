class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();

        // Create a hashmap to store the count of characters in string t
        unordered_map<char,int> mp;
        for(char &ch : t){
            mp[ch]++;
        }

        
        int countRequired = t.length();
        int i=0, j=0;
        int minWindowSize = INT_MAX;
        int startIdx = -1;

        // Slide the window and update counts
        while(j < n){
            char ch = s[j];

            // If the current character ch from string s is present in string t (i.e., its count in the hashmap mp is greater than 0),
            // decrement countRequired to indicate that one more required character has been found in the current window.
            if(mp[ch] > 0){
                countRequired--;
            }


            // keep track of the remaining occurrences of character ch in the current window 
            mp[ch]--;

            // Shrink the window until all required characters are included
            while(countRequired == 0){
                int currWindowSize = j - i + 1;

                // Update the minimum window size and start index if necessary
                if(minWindowSize > currWindowSize){
                    minWindowSize = currWindowSize;
                    startIdx = i;
                }

               
                mp[s[i]]++;
                
                // Increment countRequired if the count of character s[i] becomes positive after incrementing in the hashmap mp,
                // indicating that the character s[i] is required to form the window again.
                if(mp[s[i]] > 0){
                    countRequired++;
                }


                i++;
            }

            // Expand the window by moving the right pointer
            j++;
        }

        // Return the minimum window substring
        return minWindowSize == INT_MAX ? "" : s.substr(startIdx, minWindowSize);
    }
};


/*
    Sliding Window Approach : 

    1] Use two pointers to create a window of letters in s, which would have all the characters from t.

    2] Expand the right pointer until all the characters of t are covered.

    3] Once all the characters are covered, move the left pointer and ensure that all the characters are still covered to minimize the subarray size.

    4] Continue expanding the right and left pointers until you reach the end of s.
*/