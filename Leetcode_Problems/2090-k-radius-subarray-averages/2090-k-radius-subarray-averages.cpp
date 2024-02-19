class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        // Sliding Window Approach
        
        // If k is 0, return the input array since there's no need to calculate averages
        if (k == 0)
            return nums;

        int n = nums.size();
        vector<int> result(n, -1); 

        // If the size of the array is less than (2 * k + 1), it's not possible to calculate the k-radius averages
        if (n < (2 * k + 1))
            return result;

        // Initialize variables to mark the left and right boundaries of the first window 
        int left = 0;
        int right = 2 * k;
        long long windowSum = 0;

        // Calculate the sum of elements in the initial window
        for (int j = left; j <= right; j++) {
            windowSum += nums[j];
        }

        // Calculate the average of elements in the initial window and store it in the result array
        int i = k;
        result[i] = windowSum / (2 * k + 1);


        // Slide the window to the right and update the averages for subsequent windows
        i++;
        right++;
        while (right < n) {

            // Determine the elements leaving and entering the window
            int gone_from_window = nums[left];
            int new_to_window = nums[right];

            // Update the window sum by adding the new element and subtracting the element that's no longer in the window
            windowSum = windowSum + new_to_window - gone_from_window;

            // Calculate the average of elements in the current window and store it in the result array
            result[i] = windowSum / (2 * k + 1);

            // Move the window one position to the right
            i++;
            left++;
            right++;
        }

        return result;
    }
};
