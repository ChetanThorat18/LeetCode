class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        // Approach: Simulation as per problem definition
        int totalTime = 0;
        
        // Loop until the person at position k (index k) has bought all their tickets
        while(tickets[k] > 0){
            // Loop through all the people in the line
            for(int i = 0; i < tickets.size(); i++){
                if(tickets[i] > 0){ // If the person has remaining tickets
                    tickets[i]--; // Decrease the number of tickets they want to buy by 1
                    totalTime++; // Increase the total time taken by 1 second
                    if (i == k && tickets[i] == 0) // If the person at position k has bought all their tickets
                        break; // stop the simulation
                }
            }
        }

        return totalTime; // Return the total time taken for the person at position k to finish buying tickets
    }
};