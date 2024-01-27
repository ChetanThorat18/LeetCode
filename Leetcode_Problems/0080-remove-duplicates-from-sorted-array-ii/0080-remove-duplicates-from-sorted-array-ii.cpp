#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int i = 0;

        // Iterate through the array
        for (auto element : nums) {
            // Keep the first two occurrences of each unique element
            // or when the current element is different from the one two positions back
            if (i == 0 || i == 1 || nums[i - 2] != element) {
                nums[i] = element;
                i++;
            }
        }

        return i; // i represents the length of the modified array with at most two occurrences of each unique element
    }
};
