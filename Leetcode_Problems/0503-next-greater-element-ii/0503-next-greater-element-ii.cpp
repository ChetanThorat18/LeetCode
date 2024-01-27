class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // Approach : Loop Twice
        // Cleaner Code of Previous approach

        int n = nums.size();
        vector<int>result(n,-1);  // To store Next Greater Element 
        stack<int>stk;   // To store indices 

        for(int i=0;i<n*2;i++){
            int num = nums[i % n];  // To Wrap when i restarts from beggining
            while(  !stk.empty() && num > nums[stk.top()]  ){
                result[stk.top()] = num;
                stk.pop();
            }
            stk.push(i%n);
        }

      

        return result;
    }
};