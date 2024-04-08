class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // Approach 2: O(1) Space
        
        int n = students.size();

        // Initialize counters for students' sandwich preferences
        int stud_choice0 = 0; // Counter for students who prefer sandwich type 0
        int stud_choice1 = 0; // Counter for students who prefer sandwich type 1

        // Count the number of students preferring each sandwich type
        for(int &stud : students){
            stud == 0 ? stud_choice0++ : stud_choice1++;
        }

        // Iterate through the sandwiches and simulate serving
        for(int i=0; i<n; i++){
            int curr_sandwich = sandwiches[i];

            // If the current sandwich is of type 0
            if( curr_sandwich == 0){
                // If there are no students left who prefer this sandwich type, return the remaining unserved students
                if(stud_choice0 == 0){
                    return n-i;
                }
                // Otherwise, decrement the counter for this sandwich type
                else{
                    stud_choice0--;
                }
            } 
            // If the current sandwich is of type 1
            else{
                // If there are no students left who prefer this sandwich type, return the remaining unserved students
                if(stud_choice1 == 0){
                    return n-i;
                }
                // Otherwise, decrement the counter for this sandwich type
                else{
                    stud_choice1--;
                }
            }
        }

        // If all students are served, return 0 (no unserved students)
        return 0;
    }
};

/*
    Intuition : 

    Count no of students who prefer type-0  & type-1 Sandwich

    If , These counts are equal to count of type-0 and type-1 available in  sandwiches array , 
    Means , at some point , each of student will be definitely served.

    If count are mismatched , Some students will not be served.
*/