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
            int bloomed_already = binarySearchUpperBound(start_time, arrival);
            // Count the number of flowers that have already died before the person arrives
            int died_already = binarySearchLowerBound(end_time, arrival);

            // Calculate the net number of full bloom flowers for the current person
            result.push_back(bloomed_already - died_already);
        }

        return result;
    }

    // Binary search function to find the upper bound of the target in the array
    int binarySearchUpperBound(vector<int>& arr, int target) {
        int n = arr.size();
        int left = 0;
        int right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    // Binary search function to find the lower bound of the target in the array
    int binarySearchLowerBound(vector<int>& arr, int target) {
        int n = arr.size();
        int left = 0;
        int right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};


/*


    Upper Bound: The upper bound of an element in a sorted array is the position of the smallest element that is greater than the target. In  the binarySearchUpperBound function, we move the right pointer towards the left until we find the first element greater than the target.

    Lower Bound: The lower bound of an element in a sorted array is the position of the smallest element that is greater than or equal to the target. In the binarySearchLowerBound function, we move the right pointer towards the left until we find the first element greater than or equal to the target.


*/