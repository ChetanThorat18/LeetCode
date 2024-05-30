class Solution {
public:
    int n; 

    long long solve(vector<int>& nums, int idx, bool flag) {
        // Base case: If the index exceeds the size of the array, return 0
        if (idx >= n)
            return 0; 

        // Recursive call for skipping the current element
        // move to next index with same flag
        int skip = solve(nums, idx + 1, flag);

        int val = nums[idx]; 
        if (flag == false)
            val = -val; // If flag is false, negate the value(odd index)

        // Recursive call for taking the current element
        // move to next index by negating flag
        int take = solve(nums, idx + 1, !flag) + val;

        // Return the maximum of skipping and taking the current element
        return max(take, skip);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size(); 

        // Call the recursive function to find the maximum alternating sum
        // Start from the first index with positive flag(0 is even index)
        return solve(nums, 0, true); 
    }
};
