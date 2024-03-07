class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        // Brute Force =>  O(k . n)
        // To Minimize total , everytime we need to find pile with max no of stones
        // and remove half of its stones k times.

        int n = piles.size();

        // Iterate k times to perform the operation
        for(int i = 0; i < k; i++) {
            int maxStones = -1; // Variable to store the maximum number of stones
            int idx = -1; // Variable to store the index of the pile with the maximum stones
            
            // Find the pile with the maximum number of stones
            for(int j = 0; j < n; j++) {
                if(piles[j] > maxStones) {
                    maxStones = piles[j];
                    idx = j;
                }
            }

            // Remove half of the stones from the pile with the maximum stones
            piles[idx] = maxStones - (maxStones / 2);
        }

        int minTotal = 0; 
        // Calculate the total number of stones remaining in all piles
        for(int i = 0; i < n; i++) {
            minTotal += piles[i];
        }

        return minTotal;
    }
};
