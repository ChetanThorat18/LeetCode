class Solution {
public:
    int calculate(string s) {
        int n = s.size();

        stack<int>stk;
        int number = 0;
        int result = 0;
        int sign = 1;

        for(int i=0; i<n; i++){

            if( isdigit(s[i]) ){
                int digit = s[i] - '0'; 
                number = number * 10 + digit ; 
            }
            else if( s[i] == '+'){
                result += number * sign ;
                number = 0;
                sign = 1;
            }
            else if( s[i] == '-'){
                result += number * sign ;
                number = 0;
                sign = -1;
            }
            else if( s[i] == '(' ){
                stk.push(result);
                stk.push(sign);
                result = 0;
                number = 0;
                sign = 1;
            }
            else if( s[i] == ')' ){
                result += number * sign;
                number = 0;

                int stack_sign = stk.top(); stk.pop();
                int last_result = stk.top(); stk.pop();

                result *= stack_sign;
                result += last_result;
            }
        }

        if(number != 0)
            result += sign * number;


        return result;

    }
};


/*

Algorithm:

1. Initialize result to 0, num to 0, and sign to 1.

2. Iterate through each character in the string:
   a. If the character is a digit, update num accordingly.

   b. If the character is '+':
      i. Add the previous num to the result with the current sign.
      ii. Reset num to 0 and set sign to 1.

   c. If the character is '-':
      i. Add the previous num to the result with the current sign.
      ii. Reset num to 0 and set sign to -1.

   d. If the character is '(', push the current result and sign onto the stack, reset result to 0, and set sign to 1.

   e. If the character is ')':
      i. Pop the top two elements from the stack: prevResult and prevSign.
      ii. Add the current result to prevResult with the appropriate sign.
      iii. Update result with the new calculated result.


3. After the loop, add the last num to the result with the current sign.

4. Return the final result.

*/