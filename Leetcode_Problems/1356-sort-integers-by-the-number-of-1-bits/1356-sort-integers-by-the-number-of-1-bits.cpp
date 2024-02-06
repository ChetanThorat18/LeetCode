class Solution {
public:
    
    static bool myComparator(int &a , int &b){

        // Count the set bits in the binary representation of each number
        int a_count = __builtin_popcount(a);
        int b_count = __builtin_popcount(b);

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
    __builtin_popcount() => O(1)  

    Overall : O( nlog(n))
*/
