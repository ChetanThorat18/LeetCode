class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        // BruteForce approach

        if (k == 0)
            return nums;

        int n = nums.size(); 
        vector<int> result(n, -1); 
        
        // If the size of the array is less than 2*k + 1, return the vector with all elements as -1
        if (n < (2 * k + 1))
            return result;

       // Start the loop from index k to ensure that there are at least k elements before and after the current index
       // The loop ends at n - k to ensure that there are at least k elements after the current index
        for (int i = k; i < n - k; i++) {
            int sum = 0; // sum of elements within the window

            // Iterate over the window centered at index i with radius k
            for (int j = i - k; j <= i + k; j++) {
                sum += nums[j]; // Calculate the sum of elements within the window
            }

            // Calculate the average by dividing the sum by the number of elements in the window
            int avg = sum / (2 * k + 1); // Dividing the sum by 2k + 1 (size of the window)
            result[i] = avg; 
        }

        return result;
    }
};
