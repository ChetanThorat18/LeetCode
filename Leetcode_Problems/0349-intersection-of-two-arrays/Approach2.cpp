class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       // Approach 2

         // Create an unordered_set from nums1 to store unique elements
        unordered_set<int> st1(nums1.begin(), nums1.end());
        
        // set to store the intersection elements
        unordered_set<int> resultSet;

        // Iterate through nums2
        for(int &num : nums2) {
            // Check if the current element of nums2 is in the set of nums1 (O(1) operation)
            if(st1.find(num) != st1.end()) {
                // If found, insert it into the resultSet
                resultSet.insert(num);
            }
        }

        // Convert the resultSet to a vector 
        vector<int> result(resultSet.begin(), resultSet.end());

        return result; 
    }

};

/*
    Time Complexity : O(m+n)
*/
