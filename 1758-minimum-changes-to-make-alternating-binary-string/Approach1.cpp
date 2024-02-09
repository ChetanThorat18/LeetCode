class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        int start_with_0 = 0; // Count of operations to make string alternating starting with '0'
        int start_with_1 = 0; // Count of operations to make string alternating starting with '1'

        
        for(int i=0; i<n; i++){
            if( i % 2 == 0){
                // For even indices, expect '0' for "0 1 0 1 ..."
                if(s[i] == '0'){
                    start_with_1++; // Increment count if '0' is found instead of '1'
                }
                else{
                    start_with_0++; // Increment count if '1' is found instead of '0'
                }
            }
            else{
                // For odd indices, expect '1' for "0 1 0 1 ..."
                if(s[i] == '1'){
                    start_with_1++; // Increment count if '1' is found instead of '0'
                }
                else{
                    start_with_0++; // Increment count if '0' is found instead of '1'
                }
            }
        }

        // Return the minimum of counts for both starting patterns as the result
        return min(start_with_0, start_with_1); 
    }
};

/*
    Linearly Checking Previous Bit And Changing current if required , will not work 
    eg - "1 0 0 1 0 1 0 0"
    When i = 1  ==> s[i] != s[i-1]   continue
    When i = 2  ==> s[i] == s[i-1]   change current bit to 1 and count = 1
    When i = 3, s[i] == s[i-1]       change current bit to 0 and count = 2
    When i = 4, s[i] == s[i-1]       change current bit to 1 and count = 3
    When i = 5, s[i] == s[i-1]       change current bit to 0 and count = 4
    When i = 6, s[i] == s[i-1]       change current bit to 1 and count = 5
    When i = 7, s[i] != s[i-1]       continue.

    Here count = 5 , But Minimum Changes required are 3 (Changing 0th , 1st , 7th)  

*/


/*
    Approach 1 : 

    Alternating String can be either 
    " 0 1 0 1 0 1 0 1 ...."  => Start With 0
    " 1 0 1 0 1 0 1 0 ...."  => Start With 1

    1] Start With 0 
   ==>  Even index bit => 0 
        Odd index bit  => 1

    2] Start With 1 
   ==>  Even index bit => 1 
        Odd index bit  => 0

    For each pattern, we count the number of operations required to make the string follow that pattern.
    
    Given example: s = " 1 0 0 1 0 1 0 0"

    For pattern 1 (start with '0'):
    - At even indices (0-based indexing), we expect '0', and at odd indices, we expect '1'.
    - Count the number of operations needed to make even indices '0' and odd indices '1'.
    - Operations needed:
        - s[0] is '1', so count++
        - s[1] is '0', so count++
        - s[2] is '0', which is as expected
        - s[3] is '1', which is as expected
        - s[4] is '0', which is as expected
        - s[5] is '1', which is as expected
        - s[6] is '0', which is as expected
        - s[7] is '0', so count++

    - Total operations needed for pattern 1: count = 3

    For pattern 2 (start with '1'):
    - At even indices, we expect '1', and at odd indices, we expect '0'.
    - Count the number of operations needed to make even indices '1' and odd indices '0'.
    - Operations needed:
        s = " 1 0 0 1 0 1 0 0"

        - s[0] is '1', which is as expected
        - s[1] is '0', which is as expected
        - s[2] is '0', so count++
        - s[3] is '1', so count++
        - s[4] is '0', so count++
        - s[5] is '1', so count++
        - s[6] is '0', so count++
        - s[7] is '0', which is as expected
    - Total operations needed for pattern 2: count = 5

    Return the minimum of both Counts as the result. (i.e  => 3)

    
*/
