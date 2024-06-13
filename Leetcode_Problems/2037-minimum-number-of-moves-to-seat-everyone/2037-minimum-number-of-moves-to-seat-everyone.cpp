class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {

        // Initialize arrays to count the frequency of each seat and student position.
        vector<int> seat_position(101, 0);
        vector<int> student_position(101, 0);

        // Count the frequency of each seat position.
        for (int& seat : seats) {
            seat_position[seat]++;
        }

        // Count the frequency of each student position.
        for (int& stud_pos : students) {
            student_position[stud_pos]++;
        }

        // Initialize pointers for seat and student positions.
        int i = 0, j = 0;
        int count = 0;

        // Traverse through the arrays of seat and student positions.
        while (i <= 100 && j <= 100) {
            // Move the seat pointer to the next position that has seats available.
            while (i <= 100 && seat_position[i] == 0)
                i++;
            // Move the student pointer to the next position that has students available.
            while (j <= 100 && student_position[j] == 0)
                j++;

            // If both pointers are within bounds, calculate the moves.
            if (i <= 100 && j <= 100) {
                // Calculate the absolute difference between the current seat and student positions.
                count += abs(i - j);
                // Decrease the count of seats and students at the current positions.
                seat_position[i]--;
                student_position[j]--;
            }
        }

        // Return the total number of moves required.
        return count;
    }
};
