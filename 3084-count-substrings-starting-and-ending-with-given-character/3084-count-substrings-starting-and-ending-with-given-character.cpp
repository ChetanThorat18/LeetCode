class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long count = 0; 
        
        // count occurences of target character c in string
        for(char &ch : s) {
            if(ch == c) {
                count++; 
            }
        }
        
        // Calculate the total count of substrings starting and ending with 'c'
        // Formula: (count * (count - 1) / 2) + count
        // Explanation: count * (count - 1) / 2 calculates the number of combinations of two occurrences of 'c' within the string 's'
        //  Adding 'count' accounts for all substrings consisting of single occurrences of 'c'
        return count * (count - 1) / 2 + count;
    }
};


/*
    Intuition : 

    let s = "a  b  a  d  a"  , c = 'a'

    noOfOccurences of 'a' ==> 3

    We need a substring which starts and ends with 'a'
    i.e     "a _  _  _ a"

    We can apply simple maths here 
    No. Of positions to insert 'a' ==> 2 (at start an end position)
    No of Available 'a' ==> 3

    So result ==> 3C2 (This doesn't count single character substrings i.e "a")

    so add noOfOccurences of "a" to result 

    Final Formula =>  count * (count - 1) / 2 + count
*/