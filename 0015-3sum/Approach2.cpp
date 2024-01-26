#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        set<vector<int>> st; // Using a set to store unique triplets

        for (int i = 0; i < nums.size(); i++) {
            set<int> hashSet; // Using a set to store unique values for each iteration
            for (int j = i + 1; j < nums.size(); j++) {
                int third = -(nums[i] + nums[j]);

                // Check if the third element completes a triplet
                if (hashSet.find(third) != hashSet.end()) {
                    vector<int> temp = {nums[i], nums[j], third};
                    sort(temp.begin(), temp.end());
                    st.insert(temp); // Inserting sorted triplet into the set
                }

                hashSet.insert(nums[j]); // Insert the current element into the set
            }
        }

        return vector<vector<int>>(st.begin(), st.end()); // Converting set to vector
    }
};
