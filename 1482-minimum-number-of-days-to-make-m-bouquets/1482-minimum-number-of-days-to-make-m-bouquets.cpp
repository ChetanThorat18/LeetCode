class Solution {
public:
    
    bool isPossible(vector<int>& bloomDay, int noOfDays, int m, int k){
        int n = bloomDay.size();
        int noOfBouquets = 0;  // Counter for number of bouquets formed
        int adjCount = 0;      // Counter for adjacent flowers blooming within noOfDays

        for (int i = 0; i < n; ++i) {
            if (bloomDay[i] <= noOfDays) {
                ++adjCount;  // Increment adjacent count if flower can be used
                if (adjCount == k) {  // If we have enough adjacent flowers for one bouquet
                    ++noOfBouquets;   // Increment bouquet count
                    adjCount = 0;     // Reset adjacent count for next bouquet
                }
            } else {
                adjCount = 0;  // Reset adjacent count if current flower can't be used
            }
        }

        // Check if we formed at least m bouquets
        return noOfBouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();

        int start_day = 1;  // Minimum possible days to wait
        int end_day = *max_element(bloomDay.begin(), bloomDay.end());  // Maximum possible bloom day
        int result = -1;  

        // Binary search to find the minimum days needed
        while (start_day <= end_day) {
            int mid = start_day + (end_day - start_day) / 2;  // Calculate mid day

            // Check if it's possible to form m bouquets with k adjacent flowers using mid days
            if (isPossible(bloomDay, mid, m, k)) {
                result = mid;       // Update result to current mid (potential valid day)
                end_day = mid - 1;  // Try to find smaller valid days
            } else {
                start_day = mid + 1;  // Increase days if not possible with current mid
            }
        }

        return result;  // Return the minimum days found
    }
};