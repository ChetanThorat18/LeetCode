class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        // Brute Force : Checking for each time

        /*
            How to calculate no. of trips completed by Bus for givenTime ? 
            For eg -   time = [1,2,3]  , givenTime = 1s
            For Bus0 => tripsCompleted = givenTime / 1 = 1/1   = 1
            For Bus1 => tripsCompleted = giventime / 2 = 1/2   = 0
            For Bus2 => tripsCompleted = giventime / 3 = 1/3   = 0

            So, tripsCompleted at time = 1s is 1
        */
        int currentTime = 1;

        while(true){
            int tripsCompleted = 0;

            // Calculate the total trips completed by all buses at the current time
            for(int &t : time){
                tripsCompleted += (currentTime / t); 
            }

            // If completed-trips for currentTime matches totalTrips required , stop 
            if(tripsCompleted == totalTrips){
                break;
            }

            currentTime++;
        }

        return currentTime;
    }
};
