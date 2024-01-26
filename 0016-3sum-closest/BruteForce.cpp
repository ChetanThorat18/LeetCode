class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Brute Force (O(n^3))
        int n=nums.size();
        int minDiff = INT_MAX;
        int currentSum = 0,currentDiff=0,closestSum=0;

        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    currentSum = nums[i]+nums[j]+nums[k];
                    currentDiff = abs(currentSum - target);

                    if(currentDiff < minDiff){
                        closestSum = currentSum;
                        minDiff = currentDiff;
                    }
                }
            }
        }

        return closestSum;
    }
};
