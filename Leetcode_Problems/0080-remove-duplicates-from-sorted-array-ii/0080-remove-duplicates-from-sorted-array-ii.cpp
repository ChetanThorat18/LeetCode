class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // Initialize a pointer i to track the position where the next non-duplicate element will be placed
        int i = 0;
        
        for (int &element : nums) {
            // Check if the current element is the first or second element in the array,
            // or if the element at position i - 2 is different from the current element
            if (i == 0 || i == 1 || nums[i - 2] != element) {
                // If any of the above conditions are true, it means the current element is not a duplicate
                // or is the first occurrence of a potentially duplicated element
                
                // Place the current element at the position indicated by i in the nums array
                nums[i] = element;
                
                // Increment the pointer i to prepare for the next element
                i++;
            }
        }
        

       return i;
    }
};
