class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length(); 

        string result = ""; 

        for(int i=0; i<n; i++){ 

            // While there are still digits in the result, and there are digits to be removed (k>0),
            // and the last digit of the result is greater than the current digit of the input number,
            // remove the last digit from the result, and decrement k.
            // This is because , num[i] is not following increasing order (increasing order ==> smallest number)
            while(result.length() && k>0 && result.back() > num[i] ){
                result.pop_back();
                k--;
            }

            // If the result is not empty or the current digit of the input number is not '0',
            // append the current digit to the result.
            // This is to avoid inserting leading 0's
            if(result.length() || num[i] != '0'){
                result.push_back(num[i]);
            }
           
        }

        // Corner case
        // If input num is already in increasing order and  if there are still digits to be removed (k > 0)
        // eg = num = "12345"  k=3 then remove last k digits
        while(result.length() &&  k > 0){
            result.pop_back();
            k--;
        }

        // If the resulting string is empty, return "0"; otherwise, return the resulting string.
        if(result == ""){
            return "0";
        }

        return result;
    }
};