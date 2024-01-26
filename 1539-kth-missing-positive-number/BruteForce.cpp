class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // Brute Force O(n)

        int i=0,missingCount=0;
        int currentNumber = 1;
        while(missingCount < k ){
             // If the current number is in the array, move to the next index in the array
             if( i < arr.size()  && arr[i] == currentNumber){
                 i++;
             }
             // If the current number is missing, increment the missingCount
             else{
                missingCount++;
             }

             currentNumber++;
        }


        return currentNumber - 1;  // k^th missing 
    }
};
