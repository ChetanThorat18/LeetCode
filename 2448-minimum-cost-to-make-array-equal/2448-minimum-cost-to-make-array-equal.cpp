class Solution {
public:
    // Function to calculate the total cost for a given target value
    long long findCost(vector<int>& nums, vector<int>& cost , int target){
        long long currentCost = 0 ;
        for(int i=0;i<nums.size();i++){
            currentCost += (long long)abs(nums[i] - target) * cost[i];
        }

        return currentCost;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        // Approach : Binary Search

        long long answer = LLONG_MAX;

        int left = *min_element(begin(nums),end(nums));
        int right = *max_element(begin(nums),end(nums));

        while(left <= right){
            int mid = left + (right-left) / 2;

            // Calculate costs for the current target and the next target
            long long cost1 = findCost(nums,cost,mid);
            long long cost2 = findCost(nums,cost,mid+1);

            answer = min(cost1,cost2);

            // If cost2 is greater than cost1, it means we need to move towards lower values of target since we are looking for the minimum cost
            if(cost2 > cost1){
                right = mid-1;
            } 
            // If cost1 is greater than or equal to cost2, it means we need to move towards higher values of target since we are looking for the minimum cost
            else{
                left = mid+1;
            }
        } 

        return answer == LLONG_MAX ? 0 : answer;
    }
};