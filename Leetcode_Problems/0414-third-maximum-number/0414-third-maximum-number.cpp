class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // STL set stores elements in increasing order
        set<int>distinctSet;

        for(int &num : nums){
            //  Add the current number num to the set 
            distinctSet.insert(num);
            // If the size of the set exceeds 3, it means we have more than three distinct numbers. In this case, the smallest element (begin()) is removed from the set, ensuring that the set only contains the three largest distinct numbers.
            if(distinctSet.size() > 3){
                distinctSet.erase(distinctSet.begin());
            }
               
        }
// If size of set is exactly 3, then there are three distinct numbers, and the smallest of these three (begin()) is returned. If the size is less than 3, it means there are fewer than three distinct numbers, so the largest number in the set (rbegin()) is returned.
        return (distinctSet.size() == 3) ? *distinctSet.begin() : *distinctSet.rbegin();
    }
};