class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>mp; // Key : Player , Value : No_Of_Matches_Lost

        // Count the number of matches lost by each player
        for(int i=0; i<matches.size(); i++){
            int loser = matches[i][1];
            mp[loser]++;
        }

        vector<int>notLost; // Players who have not lost any matches
        vector<int>onceLost; // Players who have lost exactly one match

        for(int i=0; i<matches.size(); i++){
            int winner = matches[i][0];
            int loser = matches[i][1];

            // Check if the winner has not lost any matches
            if(mp.find(winner) == mp.end()){
                notLost.push_back(winner);
                mp[winner] = 2;  // Insert in map to avoid duplicates when encountered next time
            }
            // Check if the loser has lost exactly one match
            if(mp[loser] == 1){
                onceLost.push_back(loser);
            }
        }

        sort(notLost.begin(),notLost.end());
        sort(onceLost.begin(),onceLost.end());

        return {notLost , onceLost};
    }
};