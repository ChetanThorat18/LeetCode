class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int i = 0;  // Pointer i points to the position where 0 should be placed.
        int j = 0;  // Pointer j iterates through the array (Responsible for positions where 1 should be placed).
        int k = n - 1;  // Pointer k points to the position where 2 should be placed.

        while (j <= k) {

            // If the current element is 1, move to the next element
            if (nums[j] == 1) {
                j++;  
            }
            // If the current element is 2, swap it with the element at the k index and decrement k
            else if (nums[j] == 2) {
                swap(nums[j], nums[k]);  
                k--;  // Move k one step left since the element at position k is already in its correct place.
            }
            // If the current element is 0, swap it with the element at the i index, increment both i and j pointers
            else if (nums[j] == 0) {
                swap(nums[i], nums[j]);  
                i++;  // Move i one step right to place the next 0.
                j++;  // Move j to continue the iteration.
            }
        }
    }
};
