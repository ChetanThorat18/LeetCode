class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Approach 4 : Two Pointer Approach
        int n1 = nums1.size();
        int n2 = nums2.size();

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> result;

        int i = 0, j = 0; // Pointers to traverse nums1 and nums2

        // Traverse both arrays to find common elements
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                // If the elements at current positions are equal, it's a common element
                result.push_back(nums1[i]);

                // Skip over any duplicates in nums1
                while (i < nums1.size() - 1 && nums1[i] == nums1[i + 1]) {
                    i++;
                }

                // Skip over any duplicates in nums2
                while (j < nums2.size() - 1 && nums2[j] == nums2[j + 1]) {
                    j++;
                }

                // Move to the next elements in both arrays
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                // If nums1[i] is smaller, move to the next element in nums1
                i++;
            } else {
                // If nums2[j] is smaller, move to the next element in nums2
                j++;
            }
        }

        return result;
    }
};

/*
    Time Complexity : For Sorting =>  O(n1 * logn1) + O(n2 * logn2)

    O(n1 + n2)
*/
