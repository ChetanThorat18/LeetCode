class Solution {
public:
    int hammingWeight(uint32_t n) {
       // Time Complexity : O(1) 
      return __builtin_popcount(n);
    }
};