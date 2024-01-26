class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // efficient solution using bitwise XOR
        // XOR operation gives result 0 if both elements are equal 
        // n^0 = 0 i.e XOR of any element with 0 is number itself
        int ans = 0;
        for(int num:nums){
            ans = ans ^ num;
        } 
        return ans;
    }
};