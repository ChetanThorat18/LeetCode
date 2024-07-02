class Solution {
public:
    int n; 

    int solve(vector<int>& nums, vector<bool>& visited, int operation) {
        int maxScore = 0; // Initialize the maximum score for the current state

        // Iterate over all possible pairs (i, j)
        for (int i = 0; i < n - 1; i++) {
            if (visited[i]) continue; // If nums[i] has been visited, skip it

            for (int j = i + 1; j < n; j++) {
                if (visited[j]) continue; // If nums[j] has been visited, skip it

                visited[i] = true; // Mark nums[i] as visited
                visited[j] = true; // Mark nums[j] as visited

                // Calculate the score for the current operation
                int currScore = operation * __gcd(nums[i], nums[j]);

                // Recursively calculate the remaining score for subsequent operations
                int remainingScore = solve(nums, visited, operation + 1);

                // Update the maximum score by considering the current pair
                maxScore = max(maxScore, currScore + remainingScore);

                visited[i] = false; // Backtrack: Unmark nums[i]
                visited[j] = false; // Backtrack: Unmark nums[j]
            }
        }

        return maxScore; // Return the maximum score for the current state
    }

    int maxScore(vector<int>& nums) {
        n = nums.size(); 

        vector<bool> visited(n, false); // Initialize a boolean array to keep track of visited elements

        return solve(nums, visited, 1);
    }
};
