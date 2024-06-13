class Solution {
public:
    // This function checks if it's possible to ship all packages within given days with a given capacity.
    bool isPossibleToShip(vector<int>& weights, int days, int capacity) {
        int daysRequired = 1; 
        int load = 0; 

        for(int &weight : weights) { 
            // If adding the current package exceeds capacity.
            if((load + weight) > capacity) {
                daysRequired++; // Increase the number of required days.
                load = weight; // Reset the load to the weight of the current package.
            } else {
                load += weight; // Otherwise, add the weight of the current package to the load.
            }
        }

        return daysRequired <= days; // Check if the required days are less than or equal to the given days.
    }

    int shipWithinDays(vector<int>& weights, int days) {
        // Initialize the lower bound as the maximum weight package(since we have to ship all packages , hence minimum capacity should be maximum package weight)
        int low = *max_element(weights.begin(), weights.end()); 
        int arrSum = 0; 
        for(int &weight : weights) {
            arrSum += weight; 
        }

        int high = arrSum; // Initialize the upper bound as the sum of weights of all packages.

        while(low < high) { 
            int mid = low + (high - low) / 2; 

            // If it's possible to ship with mid capacity.
            if(isPossibleToShip(weights, days, mid)) { 
                high = mid; // Update the upper bound to mid to discard right search space.
            } else {
                low = mid + 1; // Otherwise, update the lower bound to mid + 1 to discard left search space.
            }
        }

        return high; // Return the minimum capacity required to ship all packages within given days.
    }
};