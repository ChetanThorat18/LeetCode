class Solution {
public:
    // Custom Comparator function for sorting
    static bool myComparator(vector<int>& a, vector<int>& b) {
        // Compare the sum of elements in vector 'a' and vector 'b'
        if (a[0] + a[1] < b[0] + b[1]) {
            // If the sum of 'a' is less than the sum of 'b', return true
            // indicating that 'a' should come before 'b' in the sorted order
            return true;
        } else {
            // Otherwise, return false indicating that 'b' should come before
            // 'a' in the sorted order or they are equal in terms of sum
            return false;
        }
    }


        vector<vector<int>> kSmallestPairs(vector<int> & nums1,vector<int> & nums2, int k) {
            // Brute Force Approach : Trying Out All possible pairs

            vector<vector<int>> result;

            // Loop through all possible pairs of elements from nums1 and nums2
            for (int i = 0; i < nums1.size(); ++i) {
                for (int j = 0; j < nums2.size(); ++j) {
                    // Add the pair [nums1[i], nums2[j]] to the result vector
                    result.push_back({nums1[i], nums2[j]});
                }
            }

            // Sort the result vector based on the sum of each pair
            sort(result.begin(), result.end(), myComparator);

            // If k is greater than the number of pairs, return all pairs
            if (k > result.size()) {
                return result;
            } else {
                // Otherwise, return only the first k pairs
                return vector<vector<int>>(result.begin(), result.begin() + k);
            }
        }
};
