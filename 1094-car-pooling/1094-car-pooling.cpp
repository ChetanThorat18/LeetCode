class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // Create an array 'location' to track passenger changes at each location
        int location[1001] = {};

        // Iterate through each trip and update the 'location' array
        for(auto arr : trips){
            // Increment passenger count at the pickup location
            location[arr[1]] += arr[0];
            // Decrement passenger count at the drop-off location
            location[arr[2]] -= arr[0];
        }

        // Iterate through the 'location' array and simulate the car's journey
        for(int i = 0; capacity >= 0 && i < 1001; i++){
            // Update the available capacity based on passenger changes at each location
            capacity -= location[i];
        }

        // If the final capacity is non-negative, it means the car can accommodate all passengers
        return capacity >= 0;
    } 
};
