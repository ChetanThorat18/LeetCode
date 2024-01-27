class Solution {
public:
    // Function to find the largest rectangle area in a histogram
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;

        // Iterate through each bar in the histogram
        for(int i = 0; i < heights.size(); i++) {
            int current = heights[i];  // Height of the current bar
          
            // Check if we can extend the rectangle to the left
            for(int j = i - 1; j >= 0; j--) {
                if(heights[j] >= heights[i]) {
                    current = current + heights[i];
                } else {
                    break;
                }
            }

            // Check if we can extend the rectangle to the right
            for(int j = i + 1; j < heights.size(); j++) {
                if(heights[j] >= heights[i]) {
                    current = current + heights[i];
                } else {
                    break;
                }
            }

            // Update the result with the maximum area encountered
            result = max(result, current);
        }

        // Return the final result
        return result;
    }
};
