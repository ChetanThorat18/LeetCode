class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // First see approach of Q. Continuos Subarray Sum

        // HashMap to store the count of each remainder when prefix sums are divided by k
        unordered_map<int, int> mp; // remainder,count

        // Initialize the map with remainder 0 having one count
        // This handles the case where the prefix sum itself is divisible by k
        mp[0] = 1;

        int count = 0;  
        int sum = 0;    // To store the cumulative sum (prefix sum)

       
        for(int &num : nums) {
            sum += num;  // Update the cumulative sum

            // Calculate the remainder of the current prefix sum when divided by k
            int remainder = sum % k;

            // If the remainder is negative, adjust it to make it positive
            // { Otherwise fails testcase eg nums = [-1,2,9] , k=2} 
            if(remainder < 0) {
                remainder += k;
            }

            // If this remainder has been seen before, it means there are subarrays ending at the current index
            // which have a sum divisible by k. Add the count of these remainders to the result count.
            if(mp.find(remainder) != mp.end()) {
                count += mp[remainder];
            }

            // Increment the count of this remainder in the map
            mp[remainder]++;
        }

        return count;  
    }
};