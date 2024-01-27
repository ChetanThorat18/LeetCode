class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // YT -> TechDose
        //https://leetcode.com/problems/single-number-ii/solutions/3714928/bit-manipulation-c-java-python-beginner-friendly

        int ones = 0;
        int twos = 0;

        for (const int num : nums) {
        ones = ones ^ (num & ~twos);
        twos = twos ^ (num & ~ones);
        }

        return ones;
        
    }
};
