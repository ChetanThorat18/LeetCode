#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& v) {
        int n = v.size();

        // Iterate through digits from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Increment the least significant digit
            if (i == n - 1)
                v[i]++;

            // Handle carry if the current digit becomes 10
            if (v[i] == 10) {
                v[i] = 0;

                // If not the leftmost digit, propagate the carry to the next digit
                if (i != 0) {
                    v[i - 1]++;
                }
                // If the leftmost digit, add a new digit to the left and set it to 1
                else {
                    v.push_back(0);
                    v[i] = 1;
                }
            }
        }

        return v;
    }
};
