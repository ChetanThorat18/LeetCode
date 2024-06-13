class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // Create a ordered map (stores in ascending order) to store the frequency of each element in arr1
        map<int,int> mp;

        // Count the frequency of each element in arr1
        for(int& num : arr1){
            mp[num]++;
        }

        // Iterate through arr2 to maintain relative ordering
        int i=0;
        for(int& num : arr2){
            // Place the elements from arr2 into arr1 according to their frequency
            while(mp[num] > 0){
                arr1[i] = num;
                i++;
                mp[num]--;
            }
        }

        // Place the remaining elements from arr1 (not in arr2) at the end in ascending order
        for(auto& itr : mp){
            int freq = itr.second;
            while(freq){
                arr1[i] = itr.first;
                i++;
                freq--;
            }
        }

        return arr1;
    }
};
