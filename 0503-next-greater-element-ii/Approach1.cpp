class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // Approach : Loop Twice

        int n = nums.size();
        vector<int>result(n,-1);  // To store Next Greater Element 
        stack<int>stk;   // To store indices 

         // First loop: Finding the Next Greater Element for elements in a single pass
        for(int i=0;i<n;i++){
            while(  !stk.empty() && nums[i] > nums[stk.top()]  ){
                result[stk.top()] = nums[i];
                stk.pop();
            }
            stk.push(i);
        }

        // Second loop: Handling circular array by traversing from the beginning to the last element (To find next greater element of last element)
        for(int i=0;i<n;i++){
            while( !stk.empty() && nums[i] > nums[stk.top()] ){
                result[stk.top()] = nums[i];
                stk.pop();
            }
            if(stk.empty())
                break;
        }

        return result;
    }
};
