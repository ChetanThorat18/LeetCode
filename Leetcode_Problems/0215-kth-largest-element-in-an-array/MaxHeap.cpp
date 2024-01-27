class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //construct max-heap(largest element at root)
        priority_queue<int>pq(nums.begin(),nums.end());
        //pop k-1 elements
        for(int i=0;i<k-1;i++){
            pq.pop();
        }
        //return kth element from top(which will be kth largest)
        return pq.top();
    }
};
