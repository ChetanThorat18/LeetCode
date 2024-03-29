class Solution {
public:
    int pivotInteger(int n) {
        // Initialize two pointers i and j to the first and last elements respectively
        int i = 1;
        int j = n;

        // Initialize leftSum to sum of elements from 1 to i, and rightSum to sum of elements from i to j
        int leftSum = 1;
        int rightSum = n;

        // Loop until i is less than j
        while (i < j) {
            // If left sum is less than right sum, move i to the right and update leftSum
            if (leftSum < rightSum) {
                i++;
                leftSum += i;
            }
            // If left sum is greater than or equal to right sum, move j to the left and update rightSum
            else {
                j--;
                rightSum += j;
            }
        }

        // After loop is break , i will be equal to j , then check for leftSum and rightSum
        // If leftSum and rightSum are equal, return the pivot integer i, otherwise return -1
        return leftSum == rightSum ? i : -1;
    }
};
