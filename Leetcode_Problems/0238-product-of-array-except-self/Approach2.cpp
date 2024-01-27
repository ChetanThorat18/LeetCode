class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
/*         APPROACH :

For each element , calculate product of all elements to its left and product of all elements to its right
        
*/
        int n = nums.size();
        vector<int>result(n);
        vector<int>left_product(n);
        vector<int>right_product(n);

       // For the first element, there is no element to its left.
        left_product[0] = 1;

        // left_product[i] represents product of all elements to left of nums[i]
        for(int i=1; i<n; i++){
            // left_product[i] = product of all elements to left of nums[i-1]  * previous element(nums[i-1])
            left_product[i] = left_product[i-1] * nums[i-1];
        }

        // For the last element, there is no element to its right.
        right_product[n-1] = 1;

        // right_product[i] represents product of all elements to right of nums[i]
        for(int i = n-2; i>=0; i--){
             // right_product[i] = product of all elements to right of nums[i+1]  * next element(nums[i+1])
            right_product[i] = right_product[i+1] * nums[i+1];
        }

        // The result for each element is the product of the corresponding left and right products.
        for(int i=0; i<n; i++){
            result[i] = left_product[i] * right_product[i];
        }

        return result;
    }
};
