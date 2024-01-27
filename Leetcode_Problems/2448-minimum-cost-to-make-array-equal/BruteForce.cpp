class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        // Brute Force

        long long minCost = LLONG_MAX;

        // Find Cost for making all numbers equal to current number
        for(int i=0; i<nums.size(); i++){
            long long currentCost = 0;
            for(int j=0; j<nums.size();j++){
                if(j != i){
                   int diff = abs(nums[i] - nums[j]);
                   currentCost += (long long)diff * cost[j]; 
                }
            }

            minCost = min(minCost , currentCost);
        }

        return minCost;
    }
};
