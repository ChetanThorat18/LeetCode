class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Initialize a pointer 'j' to 1, representing the index for unique elements.
        int j = 1;

        // Iterate through the array starting from index 1.
        for (int i = 1; i < nums.size(); i++) {
            // Check if the current element is different from the previous one.
            if (nums[i] != nums[i - 1]) {
                // If different, place the current unique element at index 'j'.
                nums[j] = nums[i];
                // Increment 'j' for the next unique element.
                j++;
            }
        }

        // Return the final value of 'j', representing the number of unique elements.
        return j;
    }
};
