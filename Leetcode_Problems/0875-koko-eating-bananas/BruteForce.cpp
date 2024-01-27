class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long currentSpeed = 1;

        while(true){
            long long totalHours = 0;

            // For each pile , Calculate the total hours required to eat all bananas at the current speed
            for(int &pile  : piles){
                // Eg- pile = 6 & currentSpeed = 3 ==> totalHours = 6/3 = 2 
                totalHours += pile  / currentSpeed;

                // If there are remaining bananas after eating whole piles, add an extra hour
                // Eg- pile = 8 & currentSpeed = 3 , remaining 2 bananas will require 1 more hour 
                if(pile  % currentSpeed != 0){
                    totalHours++;
                }
            }

            if(totalHours <= h){
                break;
            }

            currentSpeed++;
        }

        return currentSpeed;
    }
};
