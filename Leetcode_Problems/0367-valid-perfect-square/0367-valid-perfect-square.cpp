class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1)
            return true;

        int left = 1;
        int right = num/2;

        while(left <= right){
            int mid = left + (right - left )/2 ;

            long long square = (long long)mid * mid;

            if(square == num){
                // Found a perfect square
                return true;
            }
            else if(square > num){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return false;
    }
};