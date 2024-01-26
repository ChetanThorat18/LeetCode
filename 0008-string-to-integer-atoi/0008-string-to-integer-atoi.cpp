class Solution {
public:
    int myAtoi(string str) {
        //1. Empty string
        if(str.size() == 0) return 0;

       int i=0 , sign = 1 , result = 0;

        // Ignore leading whitespaces (if any)
       while(i<str.size() &&  str[i] == ' ')
           i++;

        // Now check Sign (+ or -) if any
        if(str[i] == '+')
            i++;
        else if(str[i] == '-'){
            sign = -1;
            i++;
        }
        // if current character is digit(0-9) , update result
        while(i < str.size()){
            // if current character is not a digit then ignore rest of string
            if(str[i] == ' ' ||  !isdigit(str[i]))
                break;

            int digit = str[i] - '0';
    
/*
        This part of the condition checks if multiplying the current value of result by 10 would exceed or equal INT_MAX.
        If this is true, it means that adding the next digit would lead to an overflow, and the function returns INT_MAX if the sign is    positive.
        (result == INT_MAX / 10 && digit > INT_MAX % 10):

        This part checks if multiplying the current value of result by 10 equals INT_MAX, and adding the next digit (digit) would exceed the remaining space in the INT_MAX range.
        It considers the case where the result is already at the maximum limit, and adding the next digit would cause an overflow.

*/
           if( (result > INT_MAX / 10 ) || (result == INT_MAX / 10   && digit > INT_MAX % 10 )   ){
               if(sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN; 
           }

            result = (10 * result) + digit;

            i++;
        }

        return sign*result;
    }
};