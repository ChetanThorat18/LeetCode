/* First See Problem No. 560 */
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(); 
        unordered_map<int, int> mp; // hashmap to store cumulative sums along with their indices

        int maxLength = 0; 
        int currSum = 0; 
        mp[0] = -1; // Insert an initial entry into the hashmap to handle cases where the cumulative sum equals 0

        for(int i = 0; i < n; i++) {
            // Update the cumulative sum based on the current element (increment by 1 for '1', decrement by 1 for '0')
            currSum += (nums[i] == 1) ? 1 : -1;

            // If the current cumulative sum has been encountered before, calculate the length of subarray
            if(mp.find(currSum) != mp.end()) {
                // Get the index of the previous occurrence of the cumulative sum
                int prevIdx = mp[currSum];

                int currLength = i - prevIdx;
                // Update the maxLength 
                maxLength = max(maxLength, currLength);
            } else {
                // If the cumulative sum is encountered for the first time, store its index in the hashmap
                mp[currSum] = i;
            }
        }
        return maxLength; 
    }
};


/*
    Intuition : 
       (Treat 0's as -1)

                i     j
    let nums = [0  0  1  0  0  0  1  1 ]  and targetSum = 0

    totalSum till i ==> -1
    totalSum till j ==>  -1   (  (-1) + (-1) + (1) )

    This means , There Exist subarray between i and j with totalSum = 0
    i.e In this case , it means Subarray with equal no of 0's and 1's

    So , length of this subarray will be (j-1) i.e  2

    Continue this Until End of Array to find maximum Length Subarray   

    
*/