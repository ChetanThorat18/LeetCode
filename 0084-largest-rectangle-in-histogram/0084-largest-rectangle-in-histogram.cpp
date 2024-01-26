#include <vector>

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int result = 0;

        // Array to store the index of the nearest smaller element on the left for each bar
        vector<int> prevSmaller(n, -1); // Initialize with -1

        // Calculate the nearest smaller element on the left for each bar
        for (int i = 1; i < n; i++) {
            int j = i - 1;
            while (j >= 0 && heights[j] >= heights[i]) {
                j = prevSmaller[j];
            }
            prevSmaller[i] = j;
        }

        // Array to store the index of the nearest smaller element on the right for each bar
        vector<int> nextSmaller(n, n); // Initialize with n

        // Calculate the nearest smaller element on the right for each bar (move backward)
        for (int i = n-2; i >= 0; i--) {
            int j = i + 1;
            while (j < n && heights[j] >= heights[i]) {
                j = nextSmaller[j];
            }
            nextSmaller[i] = j;
        }
        
        // Calculate the maximum area by considering each bar as the height of the rectangle
        for (int i = 0; i < n; i++) {
            int currentArea = (nextSmaller[i] - prevSmaller[i] - 1) * heights[i];
            result = max(result, currentArea);
        }

        return result;
    }
};
