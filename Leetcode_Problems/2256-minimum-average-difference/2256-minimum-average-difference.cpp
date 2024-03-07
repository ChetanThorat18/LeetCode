class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();

        // Calculate the total sum of all elements in nums
        long long totalSum = 0;
        for(int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

        long long leftSum = 0, rightSum = 0;
        int minDiff = INT_MAX;
        int resultIdx = -1;

        for(int i = 0; i < n; i++) {
            // Calculate the left sum by adding the current element to the left sum
            leftSum += nums[i];
            // Calculate the right sum by subtracting the left sum from the total sum
            rightSum = totalSum - leftSum;

            // Calculate the number of elements on the left and right sides
            int n1 = i + 1;          // Number of elements on the left (including the current element)
            int n2 = n - 1 - i;      // Number of elements on the right (excluding the current element)

            // Calculate the average of the elements on the left side 
            int leftAvg = leftSum / n1;
            // Calculate the average of the elements on the right side 
            int rightAvg = (i == n - 1) ? 0 : rightSum / n2; // Handle case when i is at the last index(Divide By Zero Error)

            // Calculate the absolute difference between the left and right averages
            int currentDiff = abs(leftAvg - rightAvg);

            // Update minDiff and resultIdx if the current difference is smaller
            if(currentDiff < minDiff) {
                minDiff = currentDiff;
                resultIdx = i;
            }
        }

        return resultIdx;
    }
};


/*
    Time Complexity : O(n)
*/
