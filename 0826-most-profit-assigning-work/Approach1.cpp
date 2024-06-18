class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // Brute Force approach

        int m = worker.size();  
        int n = difficulty.size();  

        int result = 0;  // Initialize the result to store the total maximum profit

        // Iterate over each worker
        for (int i = 0; i < m; i++) {
            int worker_ability = worker[i];  // Current worker's ability
            int maxProfit = 0;  // Initialize the maximum profit for the current worker

            // Iterate over each job
            for (int j = 0; j < n; j++) {
                // Check if the worker can complete the job
                if (worker_ability >= difficulty[j]) {
                    // Update the maximum profit for the current worker
                    maxProfit = max(maxProfit, profit[j]);
                }
            }

            // Add the maximum profit the current worker can achieve to the total result
            result += maxProfit;
        }

        // Return the total maximum profit achieved by all workers
        return result;
    }
};
