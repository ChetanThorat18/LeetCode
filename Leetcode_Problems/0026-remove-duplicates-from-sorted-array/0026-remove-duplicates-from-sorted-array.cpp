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


/*********************************************************************************************************/


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = 1;
        // i ==> i will insert unique character found by j
        // j ==> j will search for unique character
        while (j < n) {
            // If character at i and j are not equal , means we have got a unique character
            if (nums[i] != nums[j]) {
                // Insert unique character at position pointed by i
                nums[++i] = nums[j];
            }

            // j will keep searching for unique character
            j++;
        }

        // return number of unique characters found 
        return i+1;
    }
};
