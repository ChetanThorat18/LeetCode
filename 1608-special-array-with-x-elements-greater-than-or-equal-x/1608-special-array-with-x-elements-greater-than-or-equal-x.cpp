class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int n = nums.size();

        // Iterate over possible values of x
        for(int x = 0; x <= n; x++){
            // Find the index of the first element greater than or equal to x using binary search
            int idx = lower_bound(nums.begin(), nums.end(), x) - nums.begin();

            // Calculate the count of numbers greater than or equal to x
            int count = n - idx;
            
            // If the count matches x, return x
            if(count == x)
                return x;
        }

        // If no such x is found, return -1
        return -1;
    }
};
