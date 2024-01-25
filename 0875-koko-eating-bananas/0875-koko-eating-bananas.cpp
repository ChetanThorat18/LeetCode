class Solution {
public:
    // Function to check if Koko can eat all bananas within h hours at a given speed
    bool canEatAll(vector<int>&piles, int currentSpeed , int hrs){
        int totalHours = 0;

        // For each pile , Calculate the total hours required to eat all bananas at the current speed
        for(int &pile : piles){
            totalHours += pile / currentSpeed;

            // If there are remaining bananas after eating whole piles, add an extra hour
            if(pile % currentSpeed != 0){
                totalHours++;
            }
        
        }

       return totalHours <= hrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // Approach : Binary Search

        int low = 1;
        // We can choose any larger value , but we will choose max_value from piles
        int high = *max_element(begin(piles),end(piles));   

        while(low < high){
            int mid = low + (high - low)/2;  // mid => currentSpeed

            // If Koko can eat all bananas within h hours at the current speed, reduce the right search space , beacuse we need minimum value
            if(canEatAll(piles, mid , h)){
                high = mid;
            }
            // If Koko cannot eat all bananas within h hours at the current speed, increase the search space to the right
            else{
                low = mid + 1;
            }

        }

        return low;
    }
};