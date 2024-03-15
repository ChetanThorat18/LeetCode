class Solution {
public:
    int pivotInteger(int n) {
        // Approach : BinarySearch : O(logn) 

        // Calculate the total sum of integers from 1 to n
        int totalSum = n * (n + 1) / 2;

        int left = 1, right = n;

        while(left <= right){
            int midPivot = left + (right-left)/2;

            // As Per formula derived 
            if( midPivot * midPivot == totalSum){
                return midPivot;
            }
            else if( midPivot * midPivot < totalSum){
                left = midPivot + 1;
            }else{
                right = midPivot - 1;
            }
        }

        // If no pivot integer is found, return -1
        return -1;
    }
};
