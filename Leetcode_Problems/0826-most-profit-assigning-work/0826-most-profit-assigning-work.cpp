class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // Time Complexity : O( (n+m) logn)
        
        int m = worker.size();
        int n = difficulty.size();

        // Create a vector of pairs to store difficulty and corresponding profit
        vector<pair<int,int>> vec;

        // Fill the vector with pairs of (difficulty, profit)
        for(int i = 0; i < n; i++) {
            vec.push_back({difficulty[i], profit[i]});
        }

        // Sort the vector based on difficulty (first element of the pair)
        sort(vec.begin(), vec.end());

        // Update the profit in the vector such that vec[i].second (profit) will be maximum profit till index i
        for(int i = 1; i < n; i++) {
            vec[i].second = max(vec[i].second, vec[i-1].second);
        }

        int result = 0;
        // Iterate through each worker's ability
        for(int i = 0; i < m; i++) {
            int worker_ability = worker[i];

            // Binary search to find the maximum profit a worker with this ability can achieve
            int left = 0;
            int right = n - 1;
            int maxProfit = 0;

            while(left <= right) {
                int mid = left + (right - left) / 2;

                // If the current difficulty is greater than the worker's ability,
                // move the right pointer to mid - 1
                if(vec[mid].first > worker_ability) {
                    right = mid - 1;
                } else {
                    // Otherwise, update maxProfit and move the left pointer to mid + 1
                    maxProfit = max(maxProfit, vec[mid].second); 
                    left = mid + 1;
                }
            }

            // Add the maximum profit achievable by this worker to the result
            result += maxProfit;
        }

        return result;
    }
};
