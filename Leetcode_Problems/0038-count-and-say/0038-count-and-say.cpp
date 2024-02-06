class Solution {
public:
    string countAndSay(int n) {
        // Base case
        if( n == 1)
            return "1";

        // Recursively get the (n-1)th term
        string say = countAndSay(n-1);

        // Processing  the (n-1)th term to generate the nth term
        string result = "";

        for(int i=0; i<say.length(); i++){
            char current_char = say[i];
            int count = 1;

            // Count consecutive occurrences of the current character
            while(i < say.length() - 1 && say[i] == say[i+1]){
                count++;
                i++;
            }

            // Append the count and the current character to the result
            result += to_string(count) + string(1,current_char);
        }

        return result;
    }
};


/*
  The "Count and Say" sequence is a series of numbers in which each term is
  obtained by describing the count of consecutive digits in the previous term.
  The sequence starts with "1", and each subsequent term describes how many
  consecutive occurrences of each digit appear in the previous term.
 
  Example:
  n(1) => "1"
  n(2) => "11" (read as "one 1")
  n(3) => "21" (read as "two 1s")
  n(4) => "1211" (read as "one 2, then one 1")
  n(5) => "111221" (read as "three 1s, then two 2s, then one 1")
  n(6) ...
 
  The goal of this problem is to generate the nth term of the "Count and Say" sequence.

 */
