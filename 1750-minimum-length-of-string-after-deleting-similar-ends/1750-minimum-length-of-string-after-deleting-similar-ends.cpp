class Solution {
public:
    int minimumLength(string s) {
        // Time Complexity : O(N)

        int n = s.length();

        int i = 0, j = n - 1;

        // Iterate while there are characters remaining between the pointers and they are equal
        while (i < j && s[i] == s[j]) {
            char ch = s[i]; 

            // Move the left pointer to the right until it reaches a different character or crosses the right pointer
            while (i < j && s[i] == ch) {
                i++;
            }

            // Move the right pointer to the left until it reaches a different character or crosses the left pointer
            while (j >= i && s[j] == ch) {
                j--;
            }
        }

        // Return the remaining length of the string between the pointers(inlusive)
        return j - i + 1;
    }
};


/*
    Loop For j pointer is =>
    while( j >= i && s[j] == ch)

    Here condition is j >= i and not j > i  :

                         i   j
    Reason ==> Eg-  s = "a   a"

    After DRY RUN , i will be at index 1
    Now if we write condition j > i instead of j >= i ,
    j will not move to left , but it should have been
*/