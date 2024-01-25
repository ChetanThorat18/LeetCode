class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for(auto &i: spells){
            int j = 0;
            int k = m-1;
            while(j<=k){
                int mid = (j+k)/2;
                int long x = potions[mid];
                if(i*x<success){
                    j = mid + 1;
                }
                else{
                    k = mid - 1;
                }
            }
            ans.push_back(m-k-1);
        }
        return ans;
    }
};