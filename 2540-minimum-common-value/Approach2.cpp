class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // Time Complexity :  O(n1 + n2)
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Create an unordered_set to store unique elements of nums1
        unordered_set<int> Set(nums1.begin(), nums1.end());

        // Iterate through each element of nums2
        for(int &num : nums2){
            // Check if the current element of nums2 exists in the set
            if(Set.find(num) != Set.end()){
                // If exists, return it as the common integer
                return num;
            }
        }
        
        return -1;
    }
};
