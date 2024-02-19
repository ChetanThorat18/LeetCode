class Solution {
public:
    int minOperations(string s) {
        int n = s.length();

        int start_with_0 = 0; // Count of operations to make string alternating starting with '0'
        
        for(int i=0; i<n; i++){

            if( i % 2 == 0){
                // For even indices, expect '0' for "0 1 0 1 ..."
                if(s[i] == '1'){
                    start_with_0++; // Increment count if '1' is found instead of '0'
                }
            }
            else{
                // For odd indices, expect '1' for "0 1 0 1 ..."
                if(s[i] == '0'){
                    start_with_0++; // Increment count if '0' is found instead of '1'
                }
            }

        }

        // Calculate the count of operations to make string alternating starting with '1'
        // This is equal to the total length of the string minus the count of operations to make it alternating starting with '0'
        int start_with_1 = n - start_with_0;


        // Return the minimum of counts for both starting patterns as the result
        return min(start_with_0, start_with_1); 
    }
};