
class Solution {
public:
    int n; 

    int dp[50001];

    // Comparator function to sort jobs based on their start times
    static bool myComparator(vector<int>& v1, vector<int>& v2) {
        // Compare jobs based on their start times
        return v1[0] < v2[0];
    }

    int getNextJobIndex(vector<vector<int>>& arr, int low, int currJobEndTime) {
        int high = n - 1;
        int result = INT_MAX;

        // Perform binary search(lower bound) to find the index of the next job 
        // with start time greater than or equal to 'currJobEndTime'
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid][0] >= currJobEndTime) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }

    int solve(vector<vector<int>>& arr, int idx) {
        // Base case
        if (idx >= n)
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        // We have two choices , either consider current job or skip it

        // Case 1 : Consider current job
        // Find the index of the next job that can be scheduled after the current job ends(using lower bound)
        int nextJobIndex = getNextJobIndex(arr, idx + 1, arr[idx][1]);
        // Add profit of current job and solve recursively for next jobs
        int taken = arr[idx][2] + solve(arr, nextJobIndex);

        // Case 1 : Skip current job
        int notTaken = solve(arr, idx + 1);

        return  dp[idx]=max(taken, notTaken);
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // Approach: Recursion + Memoization
        
        n = startTime.size();

        memset(dp , -1 , sizeof(dp));
        // Create a vector of vectors to store the job details: [startTime, endTime, profit]
        vector<vector<int>> arr(n, vector<int>(3, 0));

        // Populate the vector with job details
        for (int i = 0; i < n; i++) {
            arr[i][0] = startTime[i];
            arr[i][1] = endTime[i];
            arr[i][2] = profit[i];
        }

        // Sort the jobs based on their start times
        sort(arr.begin(), arr.end(), myComparator);

        // Call the recursive function to find the maximum profit
        return solve(arr, 0);
    }
};