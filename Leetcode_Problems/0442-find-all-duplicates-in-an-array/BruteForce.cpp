class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> Set;
        
        // Initialize a vector to store the duplicate elements found
        vector<int> result;

        for(int &num : nums){
            // If the current element is already present in the set, it's a duplicate
            if(Set.count(num) > 0){
                // Add the duplicate element to the result vector
                result.push_back(num);
            } else {
                // If the current element is not present in the set, insert it
                Set.insert(num);
            }
        }

        return result;
    }
};
