class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Approach : Max-Heap

        priority_queue<int> maxHeap; 
        // construt maxHeap for array stones  
        for (int& stone : stones) {
            maxHeap.push(stone);
        }

        // Loop until there is only one stone left
        while (maxHeap.size() > 1) {

            // Extract the weights of the two heaviest stones
            int firstMaxStone = maxHeap.top();
            maxHeap.pop();
            int secondMaxStone = maxHeap.top();
            maxHeap.pop();

            // Smash the stones together
            int remainingWeight = abs(firstMaxStone - secondMaxStone);
            // Add the remaining weight to the stones
            maxHeap.push(remainingWeight);
        }

        // Return the weight of the last remaining stone
        return maxHeap.top();
    }
};

/*
    time Complexity : O(n * logn)
*/