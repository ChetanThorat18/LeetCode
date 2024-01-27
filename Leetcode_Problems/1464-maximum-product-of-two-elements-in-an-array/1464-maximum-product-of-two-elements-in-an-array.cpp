class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxElement = 0,secondMax = 0;
        for(int num : nums){
            if(num > maxElement){
                secondMax = maxElement;
                maxElement = num;
            }
            else if( num > secondMax){
                secondMax = num;
            }
        }

        return (maxElement -1 ) * (secondMax - 1);
    }
};