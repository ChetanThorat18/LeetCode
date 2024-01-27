class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        // every element appears twice except for one
        // check alternate element with its previous
        for(int i=1;i<nums.size(); i+=2 ){
            if(nums[i] != nums[i-1])
                return nums[i-1];
        }
        return nums[nums.size()-1];
    }
};
