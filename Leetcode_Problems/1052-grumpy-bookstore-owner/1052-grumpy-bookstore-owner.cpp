class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        // Step 1: Calculate initial unsatisfied customers in the first 'minutes' minutes
        int curr_Unsatisfied_Cust = 0;
        for (int i = 0; i < minutes; ++i) {
            if (grumpy[i])
                curr_Unsatisfied_Cust += customers[i];
        }

        // Initialize max_Unsatisfied_Cust with the initial unsatisfied customers
        int max_Unsatisfied_Cust = curr_Unsatisfied_Cust;

        // Step 2: Slide a window of size 'minutes' across the array to find maximum unsatisfied customers
        int i = 0, j = minutes;
        while (j < n) {
            // Include the new element at 'j' into the current window
            if (grumpy[j])
                curr_Unsatisfied_Cust += customers[j];
            
            // Remove the element that goes out of the window at 'i' from the current window
            if (grumpy[i])
                curr_Unsatisfied_Cust -= customers[i];
            
            // Update maximum unsatisfied customers found so far
            max_Unsatisfied_Cust = max(max_Unsatisfied_Cust, curr_Unsatisfied_Cust);

            // Move the window forward
            ++i;
            ++j;
        }

        // Step 3: Calculate total maximum satisfied customers
        // total maximum satisfied = total satisfied + max_Unsatisfied_Cust(Can be satisfied using technique)
        int totalMaxSatisfied = max_Unsatisfied_Cust;
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0)
                totalMaxSatisfied += customers[i];
        }

        return totalMaxSatisfied;
    }
};

