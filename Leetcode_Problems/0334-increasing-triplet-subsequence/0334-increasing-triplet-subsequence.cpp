class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
       int n = nums.size();

       // Initialize two variables to keep track of the smallest and second smallest elements
       int num1 = INT_MAX; 
       int num2 = INT_MAX; 

       for(int i=0; i<n; i++){
           int num3 = nums[i]; // Current element

           // Check if the current element is less than or equal to num1
           if(num3 <= num1){
               num1 = num3; // Update num1 to the current element
           } 
           // Check if the current element is greater than num1 but less than or equal to num2
           else if( num3 <= num2){
               num2 = num3; // Update num2 to the current element
           }
           // If the current element is greater than both num1 and num2, we've found a triplet
           else{
               // Already => num1 < num2
               // We have got num3 > num1 , num3 > num2 , indicating we found a triplet
               return true;
           }
       }  

       return false;
    }
};


/*
    if(num3 < num1){
               num1 = num3;
    } 
    else if( num3 < num2){
        num2 = num3;
    }
    else{
        return true;
    }

    Above code will not work for 
    nums = [1,1,1]
*/
