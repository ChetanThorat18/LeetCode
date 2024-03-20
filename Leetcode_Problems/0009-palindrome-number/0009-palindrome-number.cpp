class Solution {
public:
    bool isPalindrome(int x) {
        // Approach : Reverse Only the second half of number
        // Special Cases :
        // if x is negative it cannot be palindrome , if x is non-zero and ends with zero it cannot be palindrome
        // because leading zeros are not allowed

        if( x < 0 || (x != 0 && x % 10 == 0))
            return false;

        int originalNum = x;
        int reversedNum = 0;

        // loop until the first half of the digits (x) becomes less than or equal to the reversed second half (reversed)
        while( x > reversedNum){
            int reminder = x % 10;
            reversedNum = reversedNum * 10 + reminder;
            x = x /10;
        }

        // compare the first half of the digits (x) with the reversed second half (reversedNum)
        // For an even number of digits, if x is equal to reversedNum, then the number is a palindrome
        // For an odd number of digits, if x is equal to reversedNum / 10 (ignoring the middle digit), then the number is a palindrome
        return (x == reversedNum) || (x == reversedNum / 10);

    }
};

/*
    DRY RUN => 
    Let x = 12421
    => originalNum = 12421, reversedNum = 0

    Iteration 1:    reminder = 12421 % 10 = 1,  reversedNum = 0 * 10 + 1 = 1,       x = 1242
    Iteration 2:    reminder = 1242 % 10 = 2,   reversedNum = 1 * 10 + 2 = 12,      x = 124
    Iteration 3:    reminder = 124 % 10 = 4,    reversedNum = 12 * 10 + 4 = 124,    x = 12

    Now , Since second part is reversed , condition x > reversedNum does not met , and loop breaks

    Since , there are odd number of digits in original x , no need to check middle digit (4)
    Therefore , check x == reversedNum / 10  , i.e  ( 12  == (124/10)) => (12 == 12)

    return true
*/
