class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // Time Complexity: O(2n) {Two pass} = O(n)
        // Space Complexity: O(n)

        // Create a hash map to store the frequency of each number.
        unordered_map<int, int> mp;

        // First pass: Count the frequency of each number.
        for (int &num : nums) {
            mp[num]++;
        }

        int count = 0;
        // Second pass: Calculate the number of good pairs using frequency.
        for (auto &itr : mp) {
            int freq = itr.second;
            count = count + (freq * (freq - 1) / 2); // Calculate the number of pairs for each frequency.
        }

        return count;
    }
};


/*
    The line count = count + (freq * (freq - 1) / 2) calculates the number of good pairs 
    for a specific number with frequency 'freq' using the combination formula.
    
    For example, if the frequency of a particular number is 4, it means there are 4 occurrences 
    of that number in the array. To find the number of good pairs that can be formed with these occurrences, 
    we use the combination formula, specifically 4C2, which is calculated as (4 * (4 - 1) / 2), resulting in 6.
    This represents the number of ways we can choose 2 occurrences from the 4 available occurrences 
    to form pairs, and the result is then added to the overall count of good pairs in the array.
*/
