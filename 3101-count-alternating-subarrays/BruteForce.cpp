class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();

        // Initialize count to the number of elements in nums, as each individual element is an alternating subarray
        int count = n;

        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                // Check if the elements at indices j and j-1 are different
                if(nums[j] != nums[j - 1]) {
                    // If different, increment count as we have got a alternating subarray
                    count++;
                }else{
                    break;
                }
            }
        }

        return count;
    }
};
