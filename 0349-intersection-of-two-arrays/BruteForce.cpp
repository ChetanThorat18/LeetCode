class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Brute Force : O(n1*n2)
        // unordered set to store unique common elements
        unordered_set<int> Set;
        
        // Get the sizes of both arrays
        int n1 = nums1.size();
        int n2 = nums2.size();

        // For each element in nums1 check if it exists in nums2
        for(int i = 0; i < n1; i++) {
            int num1 = nums1[i];
            
            for(int j = 0; j < n2; j++) {
                // if the current element from nums2 matches the element from nums1
                if(nums2[j] == num1) {
                    //  we have found the common element
                    Set.insert(num1);
                }
            }
        }

        // Convert the set to a vector
        vector<int> result(Set.begin(), Set.end());

        return result;
    }
};
