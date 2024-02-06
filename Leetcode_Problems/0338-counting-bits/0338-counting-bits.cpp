class Solution {
public:
    vector<int> countBits(int n) {
    /*
        Approach :  Time Complexity O(n)
        count of set bits for an even number is the same as the count for its half, 
        and for an odd number, it is one more than the count for its half.

    */
       vector<int>ans(n+1);

       if(n == 0)
        return ans;

        // Base case: count of set bits for 0 is 0
        ans[0] = 0;

        for(int i=1; i<=n; i++) {
            if( (i % 2) != 0){
                ans[i] = 1 + ans[i/2];
            }
            else{
                ans[i] = ans[i/2];
            }
        }

        return ans;
    }
};


/*
   The binary representation and counts for each number from 0 to 10 are as follows:
 0: 0000 (count: 0)
 1: 0001 (count: 1)
 2: 0010 (count: 1)
 3: 0011 (count: 2)
 4: 0100 (count: 1)
 5: 0101 (count: 2)
 6: 0110 (count: 2)
 7: 0111 (count: 3)
 8: 1000 (count: 1)
 9: 1001 (count: 2)
 10: 1010 (count: 2)

 1] For even number , eg = 8 count is same as 8/2 = 4
 2] For Odd number , eg = 9 count is (1  + count(n/2))

*/