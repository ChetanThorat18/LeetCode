class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {

        vector<vector<int>>result;

        // Sort the input array
        sort(nums.begin() , nums.end());

        for(int i=0; i<nums.size(); i+=3){
            // Check if the difference between the third and first elements
            // of the current subarray is greater than k
            if( (nums[i+2] - nums[i]) > k ){
                // If the condition is violated, return an empty vector
                return {}; 
            }

            // Add the current subarray to the result
            result.push_back({nums[i],nums[i+1],nums[i+2]});
        }

        return result;
    }
};