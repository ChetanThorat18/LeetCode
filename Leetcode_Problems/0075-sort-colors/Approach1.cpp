class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Approach : Counting Sort 
        
        // Array to count the frequency of each color (0, 1, and 2)
        int freq[3] = {0};

        // Count the frequency of each color in the input array
        for(int &num : nums) {
            freq[num]++;
        } 

        // Variable to track the current position in the nums array
        int index = 0;

        // Iterate over the frequency array to place the colors in the correct order
        for(int color = 0; color <= 2; color++) {
            // Place the current color in the nums array as many times as its frequency
            while(freq[color] > 0) {
                nums[index] = color; // Assign the color to the current position
                index++; // Move to the next position in the nums array
                freq[color]--; // Decrement the frequency of the current color
            }
        }
    }
};
