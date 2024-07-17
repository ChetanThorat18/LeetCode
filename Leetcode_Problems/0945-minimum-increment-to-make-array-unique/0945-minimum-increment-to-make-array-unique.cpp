class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        
        // Find the maximum element in the array to determine the size of the frequency array.
        int maxElement = *max_element(nums.begin(), nums.end());

        // Create a frequency array large enough to cover all possible increments.
        vector<int> freq(n + maxElement, 0);

        int moves = 0;

        // Step 1: Fill the frequency array with the counts of each number in nums.
        for(int &num : nums){
            freq[num]++;
        }

        // Step 2: Traverse the frequency array to handle duplicates.
        for(int i = 0; i < freq.size(); i++){
            // If there's at most one occurrence of the current number, move to the next.
            if(freq[i] <= 1)
                continue;

            // Calculate the number of extra occurrences of the current number.
            int extra = freq[i] - 1;

            // Add these extra occurrences to the next number in the frequency array.
            freq[i + 1] += extra;

            // Set the current number's frequency to 1, as we want unique values.
            freq[i] = 1;

            // Accumulate the number of moves needed.
            moves += extra;
        }

        return moves;
    }
};