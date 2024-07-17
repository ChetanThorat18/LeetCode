class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Brute Force
        int n = nums.size();

        int maxSum = INT_MIN;

        for(int i=0; i<n; i++){
            int currSum = 0;
            for(int j=i; j<n; j++){
                currSum += nums[j];
                maxSum = max(maxSum , currSum);
            }
        }

        return maxSum;
    }
};
