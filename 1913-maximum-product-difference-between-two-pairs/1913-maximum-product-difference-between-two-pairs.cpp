class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
       // Approach 2 : Time Complexity O(n)
       // Traverse array and find largest , secondLargest , smallest , secondSmallest

        int largest = INT_MIN;
        int secondLargest = INT_MIN;
        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;

       for(int &num : nums){
           // Track largest and secondLargest
           if(num > largest){
               secondLargest = largest;
               largest = num;
           }
           else{
               secondLargest = max(secondLargest , num);
           }

           // Track smallest and secondSmallest
           if(num < smallest){
               secondSmallest = smallest;
               smallest = num;
           }
           else{
               secondSmallest = min(secondSmallest,num);
           }
       }

       return (largest * secondLargest) - (smallest * secondSmallest);
    }
};