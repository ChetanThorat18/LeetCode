class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Create an unordered map to store the frequency of each element
        unordered_map<int, int> frequencyMap;
        for (int i = 0; i < nums.size(); i++) {
            frequencyMap[nums[i]]++;
        }

        // Create a priority queue to store pairs of frequency and element
        // The priority queue is a max heap, so elements with higher frequency will have higher priority
        priority_queue<pair<int, int>> pq;

        // Iterate over the frequency map and push pairs into the priority queue
        for (auto itr = frequencyMap.begin(); itr != frequencyMap.end(); itr++) {
            pq.push(make_pair(itr->second, itr->first));
        }

        // Create a vector to store the result
        vector<int> result;

        // Extract the top k elements from the priority queue and add them to the result vector
        while (!pq.empty() && k > 0) {
            result.push_back(pq.top().second);
            pq.pop();
            k--;
        }

        return result;
    }
};
