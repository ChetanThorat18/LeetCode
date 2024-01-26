#include <unordered_set>
#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int n = nums.size();
        
        // Create a HashSet to store the numbers in the array
        std::unordered_set<int> numSet(nums.begin(), nums.end());
        
        // Check for the missing number in the range [0, n]
        for (int i = 0; i <= n; ++i) {
            if (numSet.find(i) == numSet.end()) {
                // If the current number is not found, it is the missing number
                return i;
            }
        }
        
        return -1;
    }
};
