class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();

        // Min heaps to store the costs of workers from the beginning and end
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;

        int hired = 0;
        long long ans = 0;

        int i = 0, j = n - 1;

        while (hired < k) {
            // Fill the first min heap with the costs of the next candidates from the beginning
            while (pq1.size() < candidates && i <= j) {
                pq1.push(costs[i]);
                i++;
            }

            // Fill the second min heap with the costs of the next candidates from the end
            while (pq2.size() < candidates && j >= i) {
                pq2.push(costs[j]);
                j--;
            }

            // Get the minimum cost from each min heap
            int min_pq1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int min_pq2 = pq2.size() > 0 ? pq2.top() : INT_MAX;

            // Choose the worker with the minimum cost between the two min heaps
            if (min_pq1 <= min_pq2) {
                ans += min_pq1;
                pq1.pop();
            } else {
                ans += min_pq2;
                pq2.pop();
            }

            // Increment the number of workers hired
            hired++;
        }

        return ans;
    }
};
