class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // Initialize a pointer j to keep track of non-zero element's position
        int j = 0;
        for(int element : nums){
        // If the element is non-zero, move it to the current position indicated by j
            if(element != 0){
                nums[j] = element;
                j++;
            }
        }

        // Fill the remaining positions with zeros
        while(j < nums.size()){
            nums[j] = 0;
            j++;
        }
    }
};