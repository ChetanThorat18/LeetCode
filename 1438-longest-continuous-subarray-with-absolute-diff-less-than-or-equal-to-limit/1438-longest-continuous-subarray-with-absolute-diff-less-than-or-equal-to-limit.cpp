class Solution {
public:
    typedef pair<int,int> P;  // Element, index

    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();

        // Using two heaps (priority queues)
        priority_queue<P> maxHeap;  // max heap to get maximum value in current window(subarray)
        priority_queue<P, vector<P>, greater<P>> minHeap;  // min heap to get minimum value in current window(subarray)

        int i=0, j=0;  // pointers for sliding window
        int maxLength = 0;  
        while(j < n){
            // Add current element to both heaps
            maxHeap.push({nums[j], j});
            minHeap.push({nums[j], j});

            // Check if the current window violates the condition
            // Subarray will not be valid if difference between maximum and minimum element in subarray exceeds 'limit'
            // This is becuase ==> If difference between maximum and minimum element in subarray is <= limit , then there will be no such a 
            // pair that exceeds this difference
            while(maxHeap.top().first - minHeap.top().first > limit){
                // If violated, move the left pointer (i) to right to find a valid subarray
                i = min(maxHeap.top().second, minHeap.top().second) + 1;

                // Remove elements from heaps which are out of the current window range
                
                while(maxHeap.top().second < i){
                    maxHeap.pop();
                }

                while(minHeap.top().second < i){
                    minHeap.pop();
                }
            }

            // Update maxLength with the size of the current valid subarray
            maxLength = max(maxLength, j-i+1);

            // Move the right pointer (j) to expand the window
            j++;
        }

        return maxLength;
    }
};


/*
    Heap declaration for int type : 

    1] Max- Heap
        a) priority_queue<int>maxHeap;
        b) priority_queue<int, vector<int>>maxHeap;

    2] Min-Heap
        a) priority_queue<int, vector<int>, greater<int>>minHeap;
*/