class Solution {
public:
    string intToRoman(int num) {
        // Arrays to store Roman symbols and their corresponding values
        string romanSymbols[] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int romanValues[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};

        string ans = "";

        // Iterate through each Roman symbol and its corresponding value
        for(int i = 0; i < 13; i++) {
            // Repeat the current symbol while the remaining number is greater or equal to its value
            while(num >= romanValues[i]) {
                ans += romanSymbols[i]; // Append the symbol to the result
                num -= romanValues[i];  // Subtract the corresponding value from the remaining number
            }
        }

        return ans;
    }
};
