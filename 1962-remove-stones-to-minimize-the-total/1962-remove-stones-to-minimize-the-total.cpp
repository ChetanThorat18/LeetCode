class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
       // Approach : Max-Heap
       // Intuition behind using maxHeap: We need to minimize the total sum of stones remaining after each operation. 
       // To do this, we should remove stones from the pile with the maximum number of stones. 
       // Using a max-heap allows us to efficiently extract the maximum element in each iteration.

       int n = piles.size();
       priority_queue<int> maxHeap;

       int totalSum = 0;
       // Initialize maxHeap and calculate total sum
       for(int i = 0; i < n; i++) {
           maxHeap.push(piles[i]);
           totalSum += piles[i];
       } 

       // Perform k operations
       for(int i = 0; i < k; i++) {
           // Extract the maximum element from the maxHeap
           int maxElement = maxHeap.top();
           maxHeap.pop();

           // Remove half of the stones from the maximum element
           int remove = maxElement / 2;
           maxElement -= remove;
           totalSum -= remove;

           // Push the updated maximum element back into the maxHeap
           maxHeap.push(maxElement);
       }

       return totalSum;
    }
};

/*
    Time Complexity : O(n.logn) to construct maxHeap and calculating totalSum

    O(k * logn) => performing k operations , and for each operation rearranging maxHeap(O(logn))

    Overall : O( n.logn + k.logn)
*/
