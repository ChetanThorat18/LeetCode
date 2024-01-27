class Solution {
public:
    // custom comparator
    static bool myComparator(pair<int,int>a , pair<int,int>b){
        // if both have same frequency then return larger number
        if(a.second == b.second)
            return a.first > b.first;
        // else return one with lower frequency
        else
            return a.second < b.second;
    }

    vector<int> frequencySort(vector<int>& nums) {
        map<int,int> mp;

        // store frequency of each number in map
        for(int num:nums){
            mp[num]++;
        }

        // store each key-value pair in vector s=in order to sort based on frequency
        vector<pair<int,int>>val_freq;

        for(auto each:mp){
            val_freq.push_back(each);
        }

        // sort vector val_freq using custom comparator
        sort(val_freq.begin(),val_freq.end(),myComparator);

        vector<int>result;

        for(auto v:val_freq){
            // for each pair in val_freq we have to store number(v.first) frequency times i.e v.second times
            for(int i=0; i<v.second; i++){
                result.push_back(v.first);
            }
        }

        return result;

    }
};