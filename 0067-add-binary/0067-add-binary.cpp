class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        string result="";
        int carry=0;
        while(i>=0 || j>=0){
           // sum = carry + a[i] + b[j]
           int sum = carry;
           if(i>=0) 
                sum = sum + a[i--] - '0';
            if(j>=0)
                sum = sum + b[j--] - '0';
            // + '0' to convert int sum%2 to character
            result.push_back('0' + sum % 2);
            carry = sum / 2;
        }

        // if carry is remaining add to result string
        if( carry == 1) 
            result.push_back('1');

        // reverse result string and return it
        reverse(result.begin(),result.end());
        return result;
    }
};