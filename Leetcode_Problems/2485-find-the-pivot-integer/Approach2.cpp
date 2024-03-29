class Solution {
public:
    int pivotInteger(int n) {

        // Calculate the total sum of integers from 1 to n
        int totalSum = n * (n + 1) / 2;

        // Iterate through each potential pivot integer from 1 to n
        for (int pivot = 1; pivot <= n; pivot++) {
            // Calculate the sum of integers from 1 to the current pivot integer
            int leftSum = pivot * (pivot + 1) / 2;

            // Calculate the sum of integers from the current pivot integer to n
            // Since the total sum remains constant (totalSum), we can compute the right sum
            // as totalSum - leftSum + pivot , pivot is added back since it is already subtracted while calculating leftSum
            int rightSum = totalSum - leftSum + pivot;

            // If the sums on both sides are equal, we have found the pivot integer
            if (leftSum == rightSum) {
                return pivot;
            }
        }

        // If no pivot integer is found, return -1
        return -1;
    }
};
