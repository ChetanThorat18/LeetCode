class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // Approach 1: Simulation as per problem definition

        int n = students.size();
        queue<int> stud_choice;

        // Initialize a queue to store students' sandwich preferences
        for (int i = 0; i < n; i++) {
            stud_choice.push(students[i]);
        }

        int i = 0;
        int notServed_count = 0;

        // Continue the simulation until either all students are served or some students cannot be served
        while (stud_choice.size() && notServed_count < stud_choice.size()) {
            // If the student at the front of the queue prefers the current sandwich, serve the sandwich
            if (stud_choice.front() == sandwiches[i]) {
                stud_choice.pop();
                i++;
                notServed_count = 0; // Reset the count of not served students
            } else {
                // If the student does not prefer the current sandwich, move them to the end of the queue
                int currStud_choice = stud_choice.front();
                stud_choice.pop();
                stud_choice.push(currStud_choice);
                notServed_count++; // Increment the count of not served students
            }
        }

        // Return the count of students who were not served
        return stud_choice.size();
    }
};


/*
    Intuition : 

    [1] Stopping condition =>  
        how many front elements of queue have been popped and pushed again and again.
        Once our rotations would be equal to size of queue, that means,
        now there are the students in queue, which won't be able to have lunch.


    Also, when a student gets the sandwich of his choice,
    we have to set rotations to 0. Because that means size of queue has been changed 
    and we have to re-count the rotations.
*/
