class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Brute Force using nested loops
        vector<int>result;
        for(int i=0;i<nums.size();i++){
            int product = 1;
            for(int j=0;j<nums.size();j++){
                // Skip the current element in multiplication
                if( i == j) continue;

                product = product*nums[j];
            }
            result.push_back(product);
        }

        return result;
    }
};
