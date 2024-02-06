class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
       int n  = pref.size();
       vector<int>arr(n);

       arr[0] = pref[0];

       for(int i=1; i<n; i++){
           arr[i] = pref[i] ^ pref[i-1];
       } 

       return arr;
    }
};


/*
    Input : pref = [5,2,0,3,1]
    Output : arr = [ a0, a1, a2, a3, a4]

    The goal is to find an array arr 
    Such That, 
    pref[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]

    // Base Case =>   pref[0] = arr[0]


    pref[0] = 5  => a0
    pref[1] = 2  => a0 ^ a1
    pref[2] = 0  => a0 ^ a1 ^ a2
    pref[3] = 3  => a0 ^ a1 ^ a2 ^ a3
    pref[4] = 1  => a0 ^ a1 ^ a2 ^ a3 ^ a4


    Generalised Formula :   
    eg -  pref[3] ^ pref[4]
       3  ^  1  =>  (a0 ^ a1 ^ a2 ^ a3) ^ (a0 ^ a1 ^ a2 ^ a3 ^ a4)
       3  ^  1  =>  a4


      ∴ arr[4]  =>  pref[4] ^ pref[3]
      ∴ arr[i]  =>  pref[i] ^ pref[i-1] 



 
*/