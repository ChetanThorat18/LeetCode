class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int m = flowers.size();
        int n = people.size();

        // Separate vectors to store start times and end times of flowers
        vector<int> start_time(m);
        vector<int> end_time(m);

        // Extract start and end times from the given 2D array
        for (int i = 0; i < m; i++) {
            start_time[i] = flowers[i][0];
            end_time[i] = flowers[i][1];
        }

        // Sort the start and end times separately
        sort(begin(start_time), end(start_time));
        sort(begin(end_time), end(end_time));

        vector<int> result;

        // Iterate through each person's arrival time
        for (int i = 0; i < n; i++) {
            int arrival = people[i];

            // Count the number of flowers that have already bloomed before the person arrives
            int bloomed_already = upper_bound(begin(start_time), end(start_time), arrival) - begin(start_time);

            // Count the number of flowers that have already died before the person arrives
            int died_already = lower_bound(begin(end_time), end(end_time), arrival) - begin(end_time);

            // Calculate the net number of full bloom flowers for the current person
            result.push_back(bloomed_already - died_already);
        }

        return result;
    }
};
