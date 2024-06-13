class Solution {
public:
    int n;

    vector<vector<int>>dp;

   
    // piles: the 2D vector of piles
    // i: current pile index
    // k: number of coins left to pick
    int solve(vector<vector<int>>& piles, int i, int k){

        // Base case: if we have processed all piles, return 0
        if (i >= n)
            return 0;

        if(dp[i][k] != -1)
            return dp[i][k];

        // Case 1: Do not take any coins from the current pile
        int not_taken = solve(piles, i+1, k);

        // Case 2: Take coins from the current pile
        int taken = 0;
        int sum = 0;
        
        // Iterate over the possible number of coins to take from the current pile
        for (int j = 0; j < min((int)piles[i].size(), k); j++) {
            // Add the value of the current coin to the sum
            sum += piles[i][j];

            // Calculate the maximum value by taking the current sum and the result of the recursive call
            taken = max(taken, sum + solve(piles, i+1, k - (j + 1)));
        }

        // Return the maximum value between taking and not taking coins from the current pile
        return dp[i][k] = max(taken, not_taken);
    }

    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        // Approach : Recursion + Memoization
        n = piles.size();

        dp.assign(n+1, vector<int>(k+1,-1));

        // Call the recursive function starting from the first pile and k coins
        return solve(piles, 0, k);
    }
};
