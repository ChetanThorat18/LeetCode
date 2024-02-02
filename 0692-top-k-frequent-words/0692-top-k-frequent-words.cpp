class Solution {
public:

    // Custom comparator for sorting based on frequency and lexicographical order
    static bool myComparator( pair<string,int>&p1 , pair<string,int>&p2 ){
        // If same frequency then sort lexographically(alphabetical order)
        if(p1.second == p2.second){
            return p1.first < p2.first;
        }

        // Else, Sort by frequency in descending order
        return p1.second > p2.second;
    }

    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string,int>mp;

        // Count occurrences of each word
        for(string &word : words){
            mp[word]++;
        }

        vector<pair<string,int>>vec;
        // Convert the map to a vector of pairs
        for(auto &itr : mp){
            vec.push_back({itr.first , itr.second});
        }

        // Sort the vector using the custom comparator
        sort(vec.begin() , vec.end() , myComparator);

        vector<string>result;
        // Take the top k elements from the sorted vector
        for(int i=0; i<k; i++){
            result.push_back(vec[i].first);
        }

        return result;
    }
};