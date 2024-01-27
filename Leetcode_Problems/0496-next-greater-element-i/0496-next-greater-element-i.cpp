class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
       // optimal 
        vector<int>result(nums1.size(),-1);
        unordered_map<int,int>mp;
        stack<int>stk; 

/*
    We iterate through nums2 and push each element into a stack.
    
If the current element in the iteration is greater than the top most element in the stack, then we pop it out and add the popped out element as key and the current element as the value (next greater number).

We repeat this process as long as the current element is greater than the top most element in the stack or the stack is empty.
*/
        for(int num : nums2){
            while(!stk.empty() && num > stk.top()){
                mp[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }

        for(int i=0; i<nums1.size(); i++){
            if( mp.find(nums1[i]) != mp.end() ){
                result[i] = mp[nums1[i]];
            }
        }

        return result;
    }
};