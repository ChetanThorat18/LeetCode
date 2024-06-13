class Solution {
public:
    unordered_map<string,int>mp;

    // Function to check if there are any duplicate characters between two strings
    bool hasDuplicate(string &s1, string &s2){
        int freq[26] = {0}; 

        // Update frequency array for string s1
        for(char &ch : s1){
            if( freq[ch-'a'] > 0 )
                return true; // If a character repeats, return true(s1 itself has duplicate characters)

            freq[ch-'a']++;
        }

        // Check for duplicates in string s2
        for(char &ch : s2){
            if(freq[ch-'a'] > 0)
                return true; // If a character repeats, return true
        }

        return false; // If no duplicates found, return false
    }

    // Recursive function to find the maximum possible length of a string formed by concatenating unique subsequences of arr
    int solve(vector<string>&arr , int n, int idx, string temp){
        // Base case: when we have considered all strings, return the length of the current concatenated string
        if(idx >= n)
            return temp.length(); 

        if(mp.find(temp) != mp.end())
            return mp[temp];

        int include = 0; // Length if we include the current string
        int exclude = 0; // Length if we exclude the current string

        if(hasDuplicate(arr[idx] , temp)){ // If the current string has duplicate characters with the current concatenated string
            exclude = solve(arr, n, idx+1, temp); // Exclude the current string and move to the next one
        }
        else{
            // We have to choices
            include = solve(arr, n, idx+1, temp+arr[idx]); // Include the current string and move to the next one

            exclude = solve(arr , n, idx+1, temp); // Exclude the current string and move to the next one
        }

        return mp[temp] = max(include,exclude); // Return the maximum length obtained by including or excluding the current string
    }

    int maxLength(vector<string>& arr) {
        // Approach : Recursion + memoization
        mp.clear();
        int n = arr.size(); 
        string temp = ""; 
        // Call the recursive function with initial index 0 and empty string temp
        return solve(arr,n,0,temp); 
    }
};