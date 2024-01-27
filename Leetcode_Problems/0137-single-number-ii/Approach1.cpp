class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        if(n==1)
            return nums[0];
        // Base Case 1 : unique element is at first position
        if(nums[0] != nums[1])
            return nums[0];

    
        for(int i=1; i<n; i+=3){
            // if(nums[i] == nums[i-1] ) then it forms a valid cluster of 3
            if(nums[i] != nums[i-1])
                return nums[i-1];
        }

        // Base Case 2 : unique element is at last position
        return nums[n-1];
        

        
        
    }
};
