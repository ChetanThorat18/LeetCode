class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Optimized O(n^3) no need of extra set data structure to handle duplication
        vector<vector<int>>result;

        int n = nums.size();
        if(n < 4)
            return result;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n-3;i++){
            // skip i if it is similar to previous 
            if(i > 0 && nums[i]==nums[i-1])
                continue;

            for(int j=i+1;j<n-2;j++){
                // skip j if it is similar to previous one and not immediately after to i
                if(j != i+1 && nums[j] == nums[j-1])
                    continue;

                int left = j+1;
                int right = n-1;

                while(left < right){
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right];
                    if(sum < target)
                        left++;
                    else if(sum > target)
                        right--;
                    else{ // sum == target
                        result.push_back({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;

                        // skip left and right until they are similar to previous
                        while( left < right && nums[left] == nums[left-1])
                            left++;
                        while(left < right && nums[right] == nums[right+1])
                            right--;

                    } 
                }

            }
        }
        return result;
        
    }
};