class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        // Approach : We have to find city with no outgoing edge
        // We will store 1 in map if city has outgoing edge
        unordered_map<string,int>mp;

        for(auto &path : paths){
            string src = path[0];
            mp[src] = 1;
        }

        for(auto &path : paths){
            string dest = path[1];

            if(mp[dest] != 1)
                return dest;
        }

        return "";
    }
};