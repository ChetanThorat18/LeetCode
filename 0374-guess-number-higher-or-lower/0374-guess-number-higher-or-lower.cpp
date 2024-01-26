/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 1 , high = n;

        while(low <= high){
            int guessNo = low + (high-low)/2;

            int val = guess(guessNo);  // guess() is pre-defined

            // If guessed no. is larger than target
            if(val == -1){
                high = guessNo - 1;
            }
             // If guessed no. is smaller than target
            else if( val == 1){
                low = guessNo + 1;
            }
            else{
                return guessNo;
            }
        }

        return -1;
    }
};