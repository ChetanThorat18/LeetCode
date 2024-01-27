class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
/*      Optimal : Without using Extra space

     Approach is Same as previous ,but instead of storing left_product and right_product in separate arrays ,  we directly modify the result array

*/
        int n = nums.size();
        vector<int>result(n);

        // Calculate left_product[i] and store it in the result array
        // For the first element, there is no element to its left.
        result[0] = 1;

        for(int i=1; i<n; i++){
            result[i] = result[i-1] * nums[i-1];
        }

        // update result by multiplying right_product[i]
        int right_product = 1;
        for(int i=n-1; i>=0; i--){
            result[i] = result[i] * right_product;
            right_product = right_product * nums[i];
        }

        return result;
    }
};