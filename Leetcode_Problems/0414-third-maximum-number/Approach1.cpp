class Solution {
public:
    int thirdMax(vector<int>& nums) {

        long firstMax = LONG_MIN, secondMax = LONG_MIN, thirdMax = LONG_MIN;
        for(int &num : nums){
            if(num > firstMax){
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = num;
            }
            else if( num < firstMax && num > secondMax){
                thirdMax = secondMax ;
                secondMax = num;
            }
            else if( num < secondMax && num > thirdMax){
                thirdMax = num;
            }
        }

       // If thirdMax is still LONG_MIN, it means there is no distinct third maximum,
        // so return firstMax. Otherwise, return the thirdMax.
        return (thirdMax == LONG_MIN) ? firstMax : thirdMax;

        // Variables are taken of type long because int type gives wrong output for testcase [1,2,-2147483648]
    }
};
