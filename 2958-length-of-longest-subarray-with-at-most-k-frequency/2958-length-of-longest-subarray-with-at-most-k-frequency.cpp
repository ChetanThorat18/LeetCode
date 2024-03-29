class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        // Approach : Sliding Window
        int n = nums.size();

        // Map to store the frequency of elements in the current window
        unordered_map<int,int>mp;

        int i=0, j=0; 
        int maxLength = 0; 
        
        while( j < n ){
            // Increment the frequency of the current element
            mp[nums[j]]++; 
            
            // Shrink the window until all elements have frequency less than or equal to k
            while( i < j && mp[nums[j]] > k){
                mp[nums[i]]--; // Decrement the frequency of the element at the left pointer
                i++; // Move the left pointer to the right
            }

            // Update the maximum length of the subarray
            maxLength = max(maxLength , j-i+1 );

            j++; // Move the right pointer to the right
        }

        return maxLength; 
    }
};
