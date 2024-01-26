class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Construct a min heap (smallest element at the root)
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Maintain only k elements in the min heap
        for (int element : nums) {
            if (minHeap.size() < k) {
                minHeap.push(element);
            } else {
                // If the current element is greater than the smallest element in the heap,
                // replace the smallest element with the current element
                if (element > minHeap.top()) {
                    minHeap.pop();
                    minHeap.push(element);
                }
            }
        }

        // The top of the min heap contains the kth largest element
        return minHeap.top();
    }
};
