class Solution {
public:

    // Function to count the number of set bits (1s) in a binary representation of a number
    static int countOneBits(int num){

        int count = 0;
        while(num){

            // Check if the rightmost bit is set (equal to 1)
            if( (num & 1) == 1){
                count++;
            }
            num >>= 1 ;  // Right shift to move to the next bit
        }
        return count;  
    }

    
    static bool myComparator(int &a , int &b){

        // Count the set bits in the binary representation of each number
        int a_count = countOneBits(a);
        int b_count = countOneBits(b);

        // If the counts are equal, sort in ascending order based on the actual values
        if( a_count == b_count ){
            return a < b; 
        } 

        // Sort based on the count of set bits 
        return a_count < b_count;  
    }


    vector<int> sortByBits(vector<int>& arr) {

        // Use the custom comparator function for sorting
        sort(arr.begin(), arr.end(), myComparator);

        
        return arr;
    }
};

/*
    Time Complexity : 
    For Sorting =>  O(nlogn)
    For countSetBits => O(logn)  

    Overall : O( nlog(n) * logn)
*/
