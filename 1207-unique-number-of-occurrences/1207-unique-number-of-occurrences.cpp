class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        // Count frequency for each number in the array
        for(int &num : arr){
            mp[num]++;
        }

        set<int>Set;
        for(auto &itr : mp){
            // If the frequency is already in the set, it's not unique
            if(Set.count(itr.second) > 0){
                return false;
            }
            Set.insert(itr.second);
        }

        return true;
    }
};