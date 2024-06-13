class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        // If the total number of cards is not divisible evenly by the group size,
        // it's not possible to form groups of the specified size
        if (n % groupSize != 0)
            return false;

        // Create a ordered_map to store the frequency of each card value
        map<int, int> mp;

        // Count the frequency of each card value in the hand
        for (int &card : hand) {
            mp[card]++;
        }

        while (!mp.empty()) {
            // Get the value of the first card in the map
            int currCard = mp.begin()->first;

            // Iterate through the next 'groupSize' cards
            for (int i = 0; i < groupSize; i++) {
                // If the current card + i is not present in the map or its count is 0,
                // it means it's not possible to form a group of consecutive cards
                if (mp[currCard + i] == 0)
                    return false;

                // Decrement the count of the current card + i
                mp[currCard + i]--;

                // If the count becomes 0, remove the card from the map
                if (mp[currCard + i] < 1)
                    mp.erase(currCard + i);
            }
        }

        // If we successfully form groups of consecutive cards for all elements in the hand, return true
        return true;
    }
};
