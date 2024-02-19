class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = 0;
        int sum = 0;
        int minLength = INT_MAX;

        while (right < n) {
            sum += nums[right];
            
            // If sum is greater than or equal to target, update minLength and move left pointer ( shrink the window)
            while (sum >= target) {
                minLength = min(minLength, right - left + 1);
                //  Decrement the sum by subtracting the element at index i
                sum -= nums[left];
                
                left++;
            }
            
            right++; 
        }

        return minLength == INT_MAX ? 0 : minLength;

    }
};