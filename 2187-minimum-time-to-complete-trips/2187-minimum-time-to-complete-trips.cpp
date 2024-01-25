class Solution {
public:
    bool isPossible( vector<int>&time , long long givenTime , int totalTrips){
        long long tripsCompleted = 0;
        // For each Bus , check no. of possible trips 
        for(int &t : time){
            tripsCompleted += givenTime / t;
        }

        return tripsCompleted >= totalTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        // Approach : Binary Search

        // Initialize the lower bound for time
        long long low = 1;  // Starting from 1 second

        // For example, if time = [1, 2, 3] and totalTrips = 5,
        // To determine the upper bound for binary search: (We can choose any higher value , but choose efficient one)
        // The bus with the minimum time to complete trips (i.e., time[0] = 1) will require 5 seconds to complete totalTrips, 5  
        long long high = (long long) *min_element( begin(time) , end(time))  * totalTrips;

        while(low < high){
            // calculate mid
            long long  currentTime = low + (high - low)/2;

            // If required totalTrips are possible for currentTime , reduce right search space , since we need minimum time 
            if(isPossible(time , currentTime , totalTrips)){
                high = currentTime ; // high != mid-1 , because we could loose mid which can be possible solution
            }

            // else if required totalTrips are not possible for currentTime , reduce left search space , since we will require higher values of currentTime
            else{
                low = currentTime + 1;
            }
        }


        return low;  
    }
};