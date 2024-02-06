class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
       int n = arr.size();
       if(n < 3)
        return false;

       // Check the increasing part of the array
       int i=0;
       while( (i < n-1)  && arr[i] < arr[i+1] ){
           i++;
       }

        // If complete array is in decreasing order i will remain at  0 
        // If complete array is in increasing order i will be at n-1 , return false in these cases
        if ( i == 0 || i == n - 1) {
            return false;
        }


       // continue the decreasing part of the array
       while(i < n-1 && arr[i] > arr[i+1]){
           i++;
       }

      
       return i == n-1;
    }
};
