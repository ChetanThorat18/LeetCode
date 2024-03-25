class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // Optimal Approach: Using numbers as index

        int n = nums.size();

        vector<int> result; 

        for(int i = 0; i < n; i++) {  
            int num = abs(nums[i]);  

            // Calculate the corresponding index (0-based) for num 
            // subtract 1 because for num = n , n will not b a valid index
            int index = num - 1;  

            // If the number at index 'index' is negative, it means 'num' appeared twice ,
            // As we have visited this index in past and made the value negative
            if(nums[index] < 0) {  
                result.push_back(num);  
            }
            else {
                // It means , we are first time visiting this index
                // Mark 'num' as visited by negating the number at index 'index'
                nums[index] = nums[index] * -1;  
            }
        }

        return result; 
    }
};
