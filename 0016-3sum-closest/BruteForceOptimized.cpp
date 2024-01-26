class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // Optimized O(n^2)
        sort(nums.begin(),nums.end());
        int n=nums.size();

         int closestSum = 0;
        int minDiff = INT_MAX;

        // fix one element and find remaining two using two pointer approach
        for(int i=0;i<n-2;i++){
            int left = i+1;
            int right = n-1;

            while(left < right){
                int currentSum = nums[i] + nums[left] + nums[right];
                int currentDiff = abs(currentSum-target);

                if(currentSum > target)
                    right--;

                if(currentSum < target)
                    left++;

                if(currentDiff < minDiff){
                    int minDiff = currentDiff;
                    closestSum = currentSum;
                }
            }
        }
        return closestSum;
    }
};
