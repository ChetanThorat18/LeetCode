class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       int n = nums.size();
       unordered_set<int> Set; // Set to store unique elements within the current window
       int i = 0, j = 0; // Initialize two pointers i and j for the sliding window

       while (j < n) {
           // If the distance between i and j exceeds k, remove the element at i from the set and move i forward
           // Shrink the window
           if (j - i > k) {
               Set.erase(nums[i]); 
               i++;
           }

           // If the element at j is found in the set, it means there's a duplicate within the range [i, j]
           if (Set.find(nums[j]) != Set.end()) {
               return true;
           }

           // Otherwise, insert the element at j into the set and move j forward
           Set.insert(nums[j]);
           j++;
       }

       // If no duplicates are found within any window of size k, return false
       return false;
    }
};
