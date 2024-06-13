class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;

        // Count the frequency of each number
        for(int &num : nums){
            freq[num]++;
        }

        int missingNumber = 0;
        int duplicateNumber = 0;

        // Iterate through numbers from 1 to n
        for(int i = 1; i <= n; i++){
            // If the frequency map doesn't contain i, it means i is missing
            if(freq.find(i) == freq.end()){
                missingNumber = i;
            }
            // If the frequency of i is 2, it means i is the duplicate number
            if(freq[i] == 2){
                duplicateNumber = i;
            }
        }

        // Return the duplicate number and the missing number in an array
        return {duplicateNumber, missingNumber};
    }
};
