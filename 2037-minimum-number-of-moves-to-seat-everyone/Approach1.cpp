class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // Sort the seats and students arrays
        // This ensures that each student will be assigned to the nearest available seat
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int moves = 0;

        // Iterate through each seat and student pair
        for (int i = 0; i < seats.size(); i++) {
            // Calculate the absolute difference between the seat position and student position
            // This represents the number of moves required to move the student to the seat
            moves += abs(seats[i] - students[i]);
        }

        return moves;
    }
};
