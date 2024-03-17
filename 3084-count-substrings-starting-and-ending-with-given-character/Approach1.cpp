class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long substrings = 0; //  variable to store the total number of substrings
        long long count = 0; // variable to count the occurrences of the character c in past

        for(char &ch : s) {
            // If the current character is equal to the target character c
            if(ch == c) {
                // Increment the count of substrings by 1 plus the current count
                // This adds up  all substrings starting and ending with 'c' until the current character
                substrings += 1 + count;
                
                // Increment the count of occurrences of c
                count++;
            }
        } 

        return substrings;
    }
};


/*
    Intuition : 

                   i
    let s = "a  b  a  d  a"   ,  c = 'a'

    =>  "a" is also a valid substring since it starts and ends with same charater i.e 'a'

    ==> Now , at index i , we have seen target character 'a' 1 time in past (i.e at index 0)
        So , No Of valid substrings till index i will be , [1  + past occurences of 'a']
        1  is added ==> because s[i] itself is a valid substring 
        past occurences of 'a' is added ==> beacase valid substring which can be formed is "a b a"

        So , Approach is , At any point , we will check if current character is equal to target character i.e c
        If it is equal , we will update result as [1 + past occurences of c] and 
        also increment occurence of c by 1    
*/
