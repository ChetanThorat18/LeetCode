class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Construct a min heap (smallest element at the root)
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int element : nums) {
            // Add the current element to the min heap
            minHeap.push(element);

            // If the size of the min heap exceeds k, remove the smallest element
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // The top of the min heap contains the kth largest element
        return minHeap.top();
    }
};
