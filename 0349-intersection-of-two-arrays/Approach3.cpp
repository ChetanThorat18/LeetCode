class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
       // Approach 3 : No need to use second set

         // Create an unordered_set from nums1 to store unique elements
        unordered_set<int> st1(nums1.begin(), nums1.end());
        
        vector<int>result;

        // Iterate through nums2
        for(int &num : nums2) {
            // Check if the current element of nums2 is in the set of nums1 (O(1) operation)
            if(st1.find(num) != st1.end()) {
                // If found, insert it into the resultSet
                result.push_back(num);
                st1.erase(num);
            }
        }

        return result; 
    }

};

/*
    Time Complexity : O(m+n)
*/
