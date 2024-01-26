class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // Optimized O(n^3)
        vector<vector<int>>result;
        set<vector<int>>resultSet;
        int n = nums.size();
        if(n < 4)
            return result;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int left = j+1;
                int right = n-1;

                while(left < right){
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right];
                    if(sum < target)
                        left++;
                    else if(sum > target)
                        right--;
                    else{ // sum == target
                        resultSet.insert({nums[i],nums[j],nums[left],nums[right]});
                        left++;
                        right--;
                    } 
                }

            }
        }

        for(auto arr:resultSet){
            result.push_back(arr);
        }
        return result;
        
    }
};
