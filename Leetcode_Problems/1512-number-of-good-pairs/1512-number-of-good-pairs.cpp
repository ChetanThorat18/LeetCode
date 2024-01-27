class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // Time Complexity: O(n) {Single pass}, Space Complexity: O(n)

        // Create an unordered map to store the frequency of each number
        unordered_map<int, int> mp;

        int count = 0;
        for (int &num : nums) {
            // Increment count by the current frequency of num (number of pairs formed so far)
            count += mp[num];

            // Increment the frequency of the current element in the map
            mp[num]++;
        }

        // Return the final count, representing the total number of good pairs in the array
        return count;
    }
};


/*
        Inside this loop, we are checking how many numbers we have already seen
        that are equal to the current 'num'. 

        For example:
            Consider nums = [1, 2, 3, 1, 1, 3]
               
            - For the first '1', there is no '1' in map as of now , so {count =0}
            - For the second '1', there is '1' already in map , so {count = 1}
            - For the third '1', there are two 1's already in map , so {count = count + 2}
			=> So , No of good pairs for '1' are 3 

            So, every time we encounter a new 'num', we update 'count' by the
            frequency of that 'num' that we have seen so far. After that, we
            increment the frequency of the 'num' in the map.

*/