class Solution {
public:
    void reverseString(vector<char>& s) {
      int n = s.size();
      int left = 0;
      int right = n-1;

      while(left < right){
          char tmp = s[left];
          s[left] = s[right];
          s[right] = tmp;
          
          left++;
          right--;
      }  

    }
};