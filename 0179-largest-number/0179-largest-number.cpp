#include <vector>
#include <algorithm>
#include <string>

class Solution {
public:
    // Custom comparator to determine the order of two strings
    static bool myComparator(string a, string b) {
        // Concatenate two strings in different orders and compare
        string t1 = a + b;
        string t2 = b + a;
        return t1 > t2; // Sort in descending order
    }

    // Function to arrange the numbers to form the largest number
    string largestNumber(vector<int>& nums) {
        vector<string> snums;

        // Convert integers to strings
        for (auto n : nums) {
            snums.push_back(to_string(n));
        }

        // Sort the strings using the custom comparator
        sort(snums.begin(), snums.end(), myComparator);

        // Check if the largest number is "0"
        if (snums[0] == "0") {
            return "0";
        }

        string ans = "";
        // Concatenate the sorted strings to form the largest number
        for (int i = 0; i < snums.size(); i++) {
            ans += snums[i];
        }

        return ans;
    }
};
