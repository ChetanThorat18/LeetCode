class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int>result(n);

        // Initialize indices for positive and negative numbers
        int positiveIdx = 0;
        int negativeIdx = 1;

         for(int &num : nums){
            // If the number is positive
            if(num > 0){
                // Place the positive number at the current positive index
                result[positiveIdx] = num;
                // Move the positive index to the next available position for positive numbers
                positiveIdx = positiveIdx + 2;
            }
            // If the number is negative
            else{
                // Place the negative number at the current negative index
                result[negativeIdx] = num;
                // Move the negative index to the next available position for negative numbers
                negativeIdx = negativeIdx + 2;
            }
        }
        return result;


    }
};