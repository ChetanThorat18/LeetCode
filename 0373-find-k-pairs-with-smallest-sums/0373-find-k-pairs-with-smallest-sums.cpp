class Solution {
public:
    // Define a pair (P) consisting of a sum and a pair of integers(indices)
    typedef pair<int, pair<int, int>> P;

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();

        // Declare a max heap to store pairs (sum, {index1, index2})
        priority_queue<P, vector<P>> maxHeap;

        // Iterate through all pairs of numbers from nums1 and nums2
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = nums1[i] + nums2[j];

                // If the heap size is less than k, push the current pair into the heap
                if (maxHeap.size() < k) {
                    maxHeap.push({sum, {i, j}});
                }
                // If the current sum is smaller than the maximum sum in the heap, replace it
                else if (maxHeap.top().first > sum) {
                    maxHeap.pop();
                    maxHeap.push({sum, {i, j}});
                }
                // If the current sum is greater than or equal to the maximum sum, break the loop
                // Since , for all upcoming j , sum will be higher
                else {
                    break;
                }
            }
        }

        // Extract pairs from the max heap and store them in the result vector
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            auto temp = maxHeap.top();
            maxHeap.pop();

            int i = temp.second.first;
            int j = temp.second.second;

            result.push_back({nums1[i], nums2[j]});
        }

        return result;
    }
};


/*
        priority_queue<int,vector<int>>maxHeap; 
        This is declaration of maxHeap for storing int type
*/