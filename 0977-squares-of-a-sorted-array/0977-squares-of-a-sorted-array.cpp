class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

         vector<int> result(n);
        
        int left = 0, right = n - 1; // Pointers for the left and right ends of the array
        int idx = n - 1; // Index for filling the result array from right to left
        
        while (left <= right) {
            int leftSquare = nums[left] * nums[left];
            int rightSquare = nums[right] * nums[right];
            
            // Compare squares of elements at left and right pointers
            if (leftSquare > rightSquare) {
                result[idx--] = leftSquare;
                left++;
            } else {
                result[idx--] = rightSquare;
                right--;
            }
        }
        
        return result;
    }
};