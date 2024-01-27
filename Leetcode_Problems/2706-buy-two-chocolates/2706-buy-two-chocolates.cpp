class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        // Approach 1 : Time complexity O(n)
        // Find two cheapest chocolates

        int cheapest = INT_MAX;
        int secondCheapest = INT_MAX;

        for(int &num : prices){
            if(num < cheapest){
                secondCheapest = cheapest;
                cheapest = num;
            }
            else if(num < secondCheapest ){
                secondCheapest = num;
            }
        } 

        int leftOver = money - (cheapest + secondCheapest);
        return  leftOver >= 0 ? leftOver : money; 
    }
};