class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // Brute Force

        vector<int>pairs(spells.size());
        int i=0;
        for(int &spell : spells){
            int count = 0;

            // Check each potion for forming a successful pair with the current spell
            for(int &potion : potions){
                long long product = (long long)spell * potion;
                if(product >= success)
                    count++;
            }
            
           // Set the count of successful pairs for the current spell in the result array
            pairs[i++] = count;
        }

        return pairs;
    }
};
