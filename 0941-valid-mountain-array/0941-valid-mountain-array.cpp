class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
       int n = arr.size();
       if(n < 3)
        return false;

       int i=0;
       while( (i < n-1)  && arr[i] < arr[i+1] ){
           i++;
       }
        if ( i == 0 || i == n - 1) {
            return false;
        }
       // Now , we are at peak

       while(i < n-1 && arr[i] > arr[i+1]){
           i++;
       }

       if(i == n-1){
           return true;
       }
       else{
           return false;
       }
    }
};