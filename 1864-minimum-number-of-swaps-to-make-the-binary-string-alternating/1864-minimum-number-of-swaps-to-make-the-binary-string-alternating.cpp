class Solution {
public:
    int helper(string s,char ch){
        int missingPos = 0;
        for(int i=0;i<s.size();i+=2){
            if(s[i] != ch)
                missingPos++;
        }
        return missingPos;
    }

    int minSwaps(string s) {
       int cnt0=0,cnt1=0;
       // count no. of zero's and one's
       for(int i=0;i<s.size();i++){
           if(s[i]=='1'){
               cnt1++;
           }else{
               cnt0++;
           }
       }
       // if difference between them is greater than 1 then it is not possible to make it alternative (eg-1110) 
       if(abs(cnt0-cnt1) >1){
           return -1;
       }
       // else if count of 1 is greater than 0 it means string should start with 1 (eg- 011 => 101)
       // in this case count no of missing 1's at even positions and return it(i.e at position 0,2.... )
       if(cnt1 > cnt0){
           return helper(s,'1');
       }
       // similarly if count of 0 is greater than 1 it means string should start with 0 (eg- 100 => 010)
       // in this case count no of missing 0's at even positions and return it(i.e at position 0,2.... )
       if(cnt0 > cnt1){
           return helper(s,'0');
       }

       // if no of 0's and 1's is equal , string can either start with 0 or 1
       //(eg- 111000 => 010101 OR 101010) 
       // But we have to return minimum no of swaps so we will return minimum of both 
       return min( helper(s,'1') , helper(s,'0') );
    }
};