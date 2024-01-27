class Solution {
public:
    // Helper function using two-pointer approach
    vector<int> twoPointer(vector<int>& arr, int k, int x) {
        int low = 0;
        int high = arr.size() - 1;

        // Adjust the window size until (high - low) becomes equal to k
        while ((high - low) >= k) {
            if (x - arr[low] > arr[high] - x) {
                low++;
            } else {
                high--;
            }
        }

        // Copy the elements within the window to the result vector
        vector<int> result;
        for (int i = low; i <= high; i++) {
            result.push_back(arr[i]);
        }

        return result;
    }

    // Main function to find k closest elements
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        return twoPointer(arr, k, x);
    }
};
