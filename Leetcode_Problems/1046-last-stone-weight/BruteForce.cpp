class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Loop until there is only one stone left
        while (stones.size() > 1) {
            // Sort the stones in ascending order
            sort(stones.begin(), stones.end());

            // Extract the weights of the two heaviest stones
            int firstMaxStone = stones.back();
            stones.pop_back();
            int secondMaxStone = stones.back();
            stones.pop_back();

            // Smash the stones together
            int remainingWeight = abs(firstMaxStone - secondMaxStone);
            stones.push_back(remainingWeight); // Add the remaining weight to the stones
        }

        // Return the weight of the last remaining stone
        return stones[0];
    }
};

/*
    Time omplexity : O( n * nlogn)
*/
