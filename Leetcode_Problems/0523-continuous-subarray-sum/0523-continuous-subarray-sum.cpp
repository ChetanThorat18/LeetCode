class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        // Hash map to store the first occurrence of each remainder(reminder , index)
        unordered_map<int, int> mp;

        // Initialize with a mp[0] = -1 to handle corner case
        mp[0] = -1;

        int sum = 0; 
        for (int i = 0; i < n; i++) {
            sum += nums[i]; // Update the cumulative sum

            int remainder = sum % k; // Calculate the remainder of the cumulative sum divided by k

            // If the remainder has been seen before
            if (mp.find(remainder) != mp.end()) {
                int len = i - mp[remainder]; // Calculate the length of the subarray

                // Check if the length of the subarray is at least 2
                if (len >= 2)
                    return true; // If yes, we found a valid subarray
            } else {
                // If the remainder is not seen before, store the index of its first occurrence
                mp[remainder] = i;
            }
        }

        // If no valid subarray is found, return false
        return false;
    }
};

/*
    Intuition:

    Let's say the cumulative sum so far is sum = 31, and we have k = 4.

    Compute the remainder of the sum when divided by k:
    remainder = 31 % 4 = 3

    Now, if we add k (which is 4) to the sum:
    new_sum = 31 + 4 = 35
    The new remainder when divided by k is:
    new_remainder = 35 % 4 = 3

    Notice that the remainder is still 3, the same as before.

    If we add another multiple of k (e.g., 8) to the original sum:
    new_sum = 31 + 8 = 39
    The new remainder when divided by k is:
    new_remainder = 39 % 4 = 3

    Therefore , we can observe that , if we add multiple of k (i.e. 4) to sum , we get the 
    same reminder as we were getting for original sum

    For example, if we have two indices i and j (with j > i), and the cumulative sum up to i gives remainder r, and the cumulative sum up to j also gives remainder r:
    - The sum of the subarray from i+1 to j is a multiple of k.

    This concludes that , we added multiple of k to sum thats why we get same reminder again 


    Corner case if we don't initialize mp[0] = -1
    eg-  nums[1,2,3] , k=6 


*/
