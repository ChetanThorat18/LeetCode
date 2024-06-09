
class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        
        // If k is greater than or equal to n-1, the strongest player will always win.
        // This is because the strongest player will eventually face and beat every other player
        // and will have enough wins to satisfy the condition.
        if (k >= n - 1) {
            return max_element(skills.begin(), skills.end()) - skills.begin();
        }
        
        // Use a deque to simulate the queue of players.
        deque<int> DQ;
        for (int i = 0; i < n; ++i) {
            DQ.push_back(i);
        }

        // Map to keep track of the number of consecutive wins for each player.
        unordered_map<int, int> winCountMap;
        // Flag to indicate when a player has won k games in a row.
        bool playerWin = false;

        // Simulate the competition until a player wins k games in a row.
        while (!playerWin) {
            // Get the first two players in the queue.
            int firstPlayer = DQ.front();
            DQ.pop_front();
            int secondPlayer = DQ.front();
            DQ.pop_front();

            // Get the skill levels of the two players.
            int firstPlayerSkill = skills[firstPlayer];
            int secondPlayerSkill = skills[secondPlayer];

            // Compare their skills to determine the winner.
            if (firstPlayerSkill > secondPlayerSkill) {
                // If the first player wins, increment their consecutive win count.
                winCountMap[firstPlayer]++;
                // Check if the first player has won k games in a row.
                if (winCountMap[firstPlayer] == k) {
                    playerWin = true;
                    return firstPlayer;
                }
                // The winner stays at the front, and the loser goes to the end of the queue.
                DQ.push_front(firstPlayer);
                DQ.push_back(secondPlayer);
            } else {
                // If the second player wins, increment their consecutive win count.
                winCountMap[secondPlayer]++;
                // Check if the second player has won k games in a row.
                if (winCountMap[secondPlayer] == k) {
                    playerWin = true;
                    return secondPlayer;
                }
                // The winner stays at the front, and the loser goes to the end of the queue.
                DQ.push_front(secondPlayer);
                DQ.push_back(firstPlayer);
            }
        }

        return -1;
    }
};
