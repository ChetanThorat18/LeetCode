class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0; // Initialize a pointer i for the new index

        // Iterate through the elements of nums
        for (int j = 0; j < nums.size(); j++) {
            // If the current element is not equal to val, swap it with nums[i] and increment i
            if (nums[j] != val) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
            }
        }

        return i; // i represents the number of elements in nums that are not equal to val
    }
};
