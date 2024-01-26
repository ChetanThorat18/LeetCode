class Solution {
public:
    int mySqrt(int x) {
        int start = 1;
        int end = x;

        while(start <= end){
          long mid = start + ((end-start) / 2);
            if( (long long) (mid * mid ) > x){
                end = mid - 1;
            }
            else if(mid * mid ==  x ){
                return mid;
            }
           
            else{
                start = mid+1;
            }
        }

        return end;
    }
};