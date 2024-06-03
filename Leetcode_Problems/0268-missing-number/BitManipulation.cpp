class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Approach: XOR operation
        int n = nums.size();
        
        int result = 0;
        
        // XOR all elements of the array with the result
        for(int &num : nums){
            result = result ^ num;
        }

        // XOR all numbers from 0 to n with the result
        // This will cancel out all the numbers that are present in the array
        for(int i=0; i<=n; i++){
            result = result ^ i;
        }

        // The remaining number after XOR operations is the missing number
        return result;
    }
};
