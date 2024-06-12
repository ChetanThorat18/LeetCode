
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // Create an unordered_map to store the indices of elements in arr2
        std::unordered_map<int, int> mp;

        // Store the indices of elements in arr2 in the map
        for(int i = 0; i < arr2.size(); i++) {
            mp[arr2[i]] = i;
        }

        // For elements in arr1 that are not in arr2, assign them a large index(INT_MAX)
        for(int& num : arr1) {
            if(mp.find(num) == mp.end()) {
                mp[num] = INT_MAX;
            }
        }

        // Define a custom lambda comparator function to sort arr1 based on arr2's relative order
        auto customLambdaComparator = [&](int& num1, int& num2) {
            // If indices are equal(INT_MAX), sort based on values
            if(mp[num1] == mp[num2]) 
                return num1 < num2;
            return mp[num1] < mp[num2]; // Otherwise, sort based on indices
        };

        // Sort arr1 using the custom comparator
        std::sort(arr1.begin(), arr1.end(), customLambdaComparator);

        // Return the sorted arr1
        return arr1;
    }
};