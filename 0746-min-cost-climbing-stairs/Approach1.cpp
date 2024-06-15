class Solution {
public:
    int n; 

    int solve(vector<int>& cost, int idx){
        // If we reached top of floor, no cost to add
        if(idx >= n)
            return 0; 

        // Calculate the cost to reach the top from 'idx' by taking one step or two steps
        int one_step = cost[idx] + solve(cost , idx+1); // Cost to take one step
        int two_step = cost[idx] + solve(cost , idx+2); // Cost to take two steps

        // Return the minimum cost to reach the top starting from 'idx'
        return min(one_step , two_step);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size(); 

        // Return the minimum cost to reach the top starting either from step 0 or step 1
        return min(solve(cost,0) , solve(cost,1));
    }
};
