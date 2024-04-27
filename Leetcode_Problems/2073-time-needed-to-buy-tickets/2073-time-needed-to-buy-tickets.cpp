class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        // Optimal Approach : One pass
        int n = tickets.size();;

        int time = 0;
        for(int i = 0; i < n; i++) {
            if(i <= k) { // If the person is in front of or at the same position as k
                // The time taken to buy tickets for the person at this position is the minimum of the tickets 
                // requested by the current person and the person at position k
                time += min(tickets[i], tickets[k]);
            } else { // If the person is behind position k
                // The time taken to buy tickets for the person at this position is the minimum of one less ticket
                // requested by the person at position k (since they buy one ticket for themselves in each pass)
                // and the tickets requested by the current person
                time += min(tickets[k] - 1, tickets[i]);
            }
        }

        return time;
    }
};