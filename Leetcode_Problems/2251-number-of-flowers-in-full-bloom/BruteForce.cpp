class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        // Brute Force

        vector<int> result;

        // Iterate through each person's arrival time
        for (int &p : people) {
            // Initialize count for the current person to 0
            int count = 0;

            // Iterate through each flower to check if it's in full bloom when the person arrives
            for (auto &flower : flowers) {
                int bloomFrom = flower[0];
                int bloomTill = flower[1];

                // Check if the person's arrival time falls within the full bloom period of the flower
                if (p >= bloomFrom && p <= bloomTill) {
                    count++;
                }
            }

            // Store the count in the result vector for the current person
            result.push_back(count);
        }

        return result;
    }
};
