class Solution {
public:
    int n; 
    vector<vector<long long>>memo;

    long long solve(vector<int>& nums, int idx, bool flag) {
    if (idx >= n)
        return 0; 

    if(memo[idx][flag] != -1)
        return memo[idx][flag];

    // Recursive call for skipping the current element
    // move to next index with same flag
    long long skip = solve(nums, idx + 1, flag);

    long long val = nums[idx]; 
    if (flag == false)  
        val = -val; // If flag is false, negate the value(odd index)

    // Recursive call for taking the current element
    // move to next index by negating flag
    long long take = solve(nums, idx + 1, !flag) + val;

    memo[idx][flag] = max(take,skip);

    // Return the maximum of skipping and taking the current element
    return memo[idx][flag];
}

    long long maxAlternatingSum(vector<int>& nums) {
        // Approach : Recursion + Memoization
        n = nums.size(); 

        memo.assign(n , vector<long long>(2,-1));

        // Call the recursive function to find the maximum alternating sum
        // Start from the first index with positive flag(0 is even index)
        return solve(nums, 0, true); 
    }
};
