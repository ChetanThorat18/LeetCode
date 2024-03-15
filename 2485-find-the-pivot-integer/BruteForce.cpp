class Solution {
public:
    int pivotInteger(int n) {
        // Brute Force Approach: O(n^2)

        // Iterate through each potential pivot element from 1 to n
        for(int i = 1; i <= n; i++){
            int currentElement = i;

            // Calculate the sum of elements from 1 to the current pivot element
            int leftSum = 0;
            for(int j = 1; j <= i; j++){
                leftSum += j;
            }

            // Calculate the sum of elements from the current pivot element to n
            int rightSum = 0;
            for(int k = i; k <= n; k++){
                rightSum += k;
            }

            // Check if the sums of the left and right portions are equal
            if(leftSum == rightSum) {
                // If they are equal, return the current pivot element
                // as it satisfies the condition
                return i;
            }
        }
        return -1;
    }
};
