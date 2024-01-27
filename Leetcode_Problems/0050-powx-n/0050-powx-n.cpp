class Solution {
public:
    double solve(double x,long n){
        if(n == 0)
            return 1;
        if(n < 0)
           return  solve(1/x,-n);  
        
        // if n is even 
        // eg -> x^8 can be written as => (x^2)^4 => (x*x)^4
        if(n %2 == 0)
            return solve(x*x,n/2);

        // if n is odd 
        // eg -> x^9 can be written as => x * (x^8) => x * (x*x,8/2)
        return x * solve(x*x, (n-1)/2);
    }

    double myPow(double x, int n) {
      return solve(x,(long)n); 
      // n typecasted to long to handle n = -2147483648 which cannot be made n = -n because 
      // +n can have max value = 2147483647   
    }
};