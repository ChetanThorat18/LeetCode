class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // Brute Force :  O(n1 * n2)

        int n1 = nums1.size();
        int n2 = nums2.size();

        // For each element in nums1
        for(int i = 0; i < n1; i++){
            // Iterate nums2
            for(int j = 0; j < n2; j++){
                //if the current elements of nums1 and nums2 are equal
                if(nums1[i] == nums2[j]){
                    //return the common integer found
                    return nums1[i];
                }
            }
        } 

        return -1;
    }
};
