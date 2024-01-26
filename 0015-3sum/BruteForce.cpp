#include <vector>
#include <set>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;

        if (nums.size() < 3) {
            return res;
        }

        sort(nums.begin(), nums.end()); // Sorting the input array

        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1; j < nums.size() - 1; j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        res.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        set<vector<int>> resultSet(res.begin(), res.end()); // Using a set to ensure unique triplets

        return vector<vector<int>>(resultSet.begin(), resultSet.end()); // Converting set to vector
    }
};
