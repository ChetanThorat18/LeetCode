class Solution {
public:
    int pivotInteger(int n) {
        // Appoach : Using Maths => O(1) 

        int totalSum = n*(n+1)/2;

        int pivot = sqrt(totalSum);

        return pivot*pivot == totalSum ? pivot : -1;
    }
};

/*
    Let's say Pivot = x

    totalSum = n * (n+1)/2

    Sum Of 1 to x   =   Sum of x to n
    x(x+1)/2        =    n(n+1)/2 - x(x+1)/2 + x
    2[x(x+1)/2]     =    n(n+1)/2 + x
    
    x^2 + x         =    n(n+1)/2 + x
    x^2             =    n(n+1)/2

    x^2             = totalSum

    i.e  (pivot)^2  = totalSum

*/