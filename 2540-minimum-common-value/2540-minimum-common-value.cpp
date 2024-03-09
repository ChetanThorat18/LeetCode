class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        // Two Pointers Approach : O(n1 + n2)
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Initialize two pointers, one for nums1 and one for nums2
        int i = 0, j = 0;

        // Iterate until we reach the end of either array
        while( i < n1 && j < n2){
            // If the current elements are equal, return the common element
            if(nums1[i] == nums2[j]){
                return nums1[i];
            }
            // If the element in nums1 is smaller, move the nums1 pointer forward
            else if( nums1[i] < nums2[j]){
                i++;
            }
            // If the element in nums2 is smaller, move the nums2 pointer forward
            else{
                j++;
            }
        }

        return -1;
    }
};