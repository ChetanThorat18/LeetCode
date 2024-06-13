class Solution {
public:
    int heightChecker(vector<int>& heights) {
        // Approach : Without Sorting(Counting Sort)
        // Time Complexity : O(n)

        // Create a counting array to store the frequency of each height.
        // We choose 101 as the size since the constraints mention that heights[i] <= 100.
        vector<int> count(101, 0);

        // Count the frequency of each height in the given heights array.
        for (int &height : heights) {
            count[height]++;
        }

        int i = 1, j = 0; // i is used to iterate over possible heights (from 1 to 100), j is used to iterate over the given heights array.
        int result = 0;   

        while (i < 101) {
            // If there are students with the current height.
            if (count[i] != 0) {
                // Check if the height of the student at position j is not equal to the current height i.
                // If not equal, it means this student is misplaced.
                if (heights[j++] != i)
                    result++;

                // Decrease the count of the current height, as we are considering one student of that height.
                count[i]--;
            } else {
                // If there are no students with the current height, move to the next height.
                i++;
            }
        }

        // Return the total number of misplaced students.
        return result;
    }
};