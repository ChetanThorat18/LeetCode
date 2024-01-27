class Solution {
public:
    // Main function to find k closest elements
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Create a vector of pairs to store {difference, element}
        vector<pair<int, int>> difference;

        // Calculate the absolute difference for each element and store in the vector
        for (int i = 0; i < arr.size(); i++) {
            int diff = abs(arr[i] - x);
            difference.push_back({diff, arr[i]});
        }

        // Sort the vector based on the absolute difference in ascending order
        sort(difference.begin(), difference.end());

        // Create the result vector and add the first k elements
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(difference[i].second);
        }

        // Sort the result vector in ascending order
        sort(result.begin(), result.end());

        return result;
    }
};
