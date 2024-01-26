class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;

        while (left < right) {
            // Calculate the area formed by the current container.
            int currentArea = min(height[left], height[right]) * (right - left);
            // Update the maximum area if the current area is larger.
            maxArea = max(maxArea, currentArea);

            // Move the pointers towards each other based on the height.
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }


        return maxArea;
    }
};
