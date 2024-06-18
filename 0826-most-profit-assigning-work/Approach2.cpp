class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // Time Complexity : O(nlogn + mlogm)
        
        int m = worker.size();  // Number of workers
        int n = difficulty.size();  // Number of jobs

        // Priority queue(max heap) to store jobs in the form of pairs {profit, difficulty} sorted by profit in descending order
        priority_queue<pair<int, int>> pq;

        // Populate the priority queue with jobs
        for (int i = 0; i < n; i++) {
            int diff = difficulty[i];
            int prof = profit[i];

            pq.push({prof, diff});
        }

        // Sort workers by their ability in descending order
        sort(worker.begin(), worker.end(), greater<int>());

        int i = 0;  // Worker index
        int result = 0;  // Initialize the result to store the total maximum profit

        // Iterate over the workers and assign them the highest profit job they can complete
        while (i < m && !pq.empty()) {
            int worker_ability = worker[i];  // Current worker's ability

            // Check if the current worker can complete the job with the highest profit
            if (worker_ability < pq.top().second) {
                pq.pop();  // Remove the job from the priority queue if the worker cannot complete it
            } else {
                result += pq.top().first;  // Add the job's profit to the result
                i++;  // Move to the next worker
            }
        }

        // Return the total maximum profit achieved by all workers
        return result;
    }
};
