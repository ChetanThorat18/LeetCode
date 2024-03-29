class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // Approach: Sliding Window

        // If k is less than or equal to 1, no subarray can have a product less than k
        if (k <= 1)
            return 0; 

        int n = nums.size();
        int result = 0;

        int i = 0, j = 0; 
        int subArrProd = 1; 

        // Slide the window by moving the right pointer from left to right
        while (j < n) {
            subArrProd *= nums[j]; // Include the current element in the window's product

            // Shrink the window by moving the left pointer if the product exceeds or equals k
            while (subArrProd >= k) {
                subArrProd /= nums[i]; // Exclude the leftmost element from the window's product
                i++; // Move the left pointer to the right
            }

            // Update the result by adding the length of the current window to it
            // j-i+1 => no of subarrays ending with j
            result += (j - i + 1);
            j++; // Move the right pointer to the right
        }

        return result;
    }
};
