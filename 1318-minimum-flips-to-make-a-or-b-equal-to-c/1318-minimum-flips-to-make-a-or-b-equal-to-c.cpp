class Solution {
public:
    int minFlips(int a, int b, int c) {
        // Time Complexity : O(1)
         int differingBits = (a | b) ^ c ; 
        return __builtin_popcount(differingBits) + __builtin_popcount( (a&b) & ( (a | b) ^ c) );

        // __builtin_popcount() counts the no of set bits ('1') in number 
    }
};

/*
    Step 1 => 
    a | b is what we have while c is what we want. 
    An XOR operation(if both bits are same then result = 0)
    finds the different bits that need to be flipped to achieve the desired result, i.e. (a | b) ^ c
    Eg - 

    a = 2    binary: 0010
    b = 4    binary: 0100
    c = 5    binary: 0101

    Perform bitwise OR between a and b
    a | b    binary: 0110

    XOR the result with c
    (a | b) ^ c  // binary: 0011    

    So , here 2 bits are different between a|b and c which is required No_Of_Flips
    ∴ No_Of_Flips = no of bits in XOR operation having bit = '1'

---------------------------------------------------------------------------------

    But , There is Exception in this Approach   
    There is only one case when two flips are needed => 
    bit is 0 in c but is 1 in both a and b.
    ∴ Above approach counts flips only one time in this case , But it should have count it 2 times
    Eg - 

    a = 2   binary: 0010
    b = 6   binary: 0110
    c = 5   binary: 0101

    Perform bitwise OR between a and b
    a | b   binary: 0110

    XOR the result with c
    (a | b) ^ c    binary: 0011

    In this example , second last bit in both a and b is 1 .
    Ideally , No_Of_Flips will be 3 , But Above Approach gives No_Of_Flips = 2

    So ,  We need to handle the case when both bits in a and b are '1'


    To find no of positions where both bits are '1' and we can take &(and) Operation of a and b

    For eg -  a = 1001 
              b = 1101 
        a & b = 1001  => Two positions where same '1' bit

     ∴ Now we will add this to result only when bit actually needs to flip ('1' in XOR operation)
    Eg -

    a = 7   binary: 0111
    b = 7   binary: 0111
    c = 7   binary: 0111

    Perform bitwise OR between a and b
    (a | b)  binary: 0111

    XOR the result with c
    ((a | b) ^ c)  // binary: 0000

    a & b = 0111 , it doesn't mean we directly add 3(no. of positions where bit is same in both a and b) to result
    We will Add it to result only when bit actually need to be flipped (i.e bit is '1' in XOR operation )

    ∴ Take AND opartion of  (a & b)   &    ( (a | b) ^ c)
   


   Therefore , Final Operations will be
   1] Count Different bits using XOR ==> (a | b) ^ c
   2] Add no. positions where bit is '1' in both a and b ==>   (a & b)  & ( (a|b) ^ c )


*/
