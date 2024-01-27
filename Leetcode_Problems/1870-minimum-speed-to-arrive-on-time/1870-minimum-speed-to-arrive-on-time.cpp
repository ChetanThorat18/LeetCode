class Solution {
public:
    // Function to check if it is possible to reach the office in the given time with a given speed
    bool isPossible(vector<int>&dist , int currSpeed , double hour){
        int n = dist.size();
        double time = 0.0;

        // Calculate the total time required for each train ride
        for(int i=0 ; i<n-1; i++){
            double t = (double)dist[i] / (double)currSpeed ;
            time += ceil(t);
        }
        // Add the time for the last train ride without taking ceiling since there is no train after this
        time += double(dist[n-1]) / (double)currSpeed;

        return time <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        // Approach : Binary Approach

        int left = 1;
        int right = 1e7;  // constraint : max-speed = 10^7 

        int minSpeed = -1;
        while(left <= right){
            int mid_speed = left + (right - left)/2;

            // If it is possible to reach the office with the current speed, update minSpeed and explore lower speeds
            if( isPossible(dist , mid_speed , hour) ){
                minSpeed = mid_speed;
                right = mid_speed - 1;
            }
            // If it is not possible, explore higher speeds
            else{
                left = mid_speed + 1;
            }
        }

        return minSpeed;
    }
};