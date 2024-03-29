class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0;

        for(int i=0; i<n; i++){
            // Initialize the product of the current subarray with the current element
            int subArrProd = nums[i];
            
            // If the product is less than k, increment the result count
            if(subArrProd < k){
                result++;
            }
            
            // Extend the subarray by including subsequent elements
            for(int j=i+1; j<n; j++){  
                // Multiply the current product with the next element
                subArrProd = subArrProd * nums[j];
                
                // If the product is still less than k, increment the result count
                // Otherwise, break out of the loop since the product will exceed k
                if(subArrProd < k){
                    result++;
                }else{
                    break;
                }
            }
        }

        return result;
    }
};
