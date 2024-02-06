class Solution {
public:
   
    int sumOfSquares(int num) {
        int sum = 0;
        while (num) {
            int digit = num % 10;
            sum = sum + (digit * digit);
            num = num / 10;
        }
        return sum;
    }

   
    bool isHappy(int n) {
        unordered_set<int> Set;  // HashSet to store visited numbers and detect cycles.

        while (Set.find(n) == Set.end()) {
            Set.insert(n);  // Add the current number to the HashSet.

            n = sumOfSquares(n);  // Replace the number with the sum of the squares of its digits.

            if (n == 1) {
                return true;  // If the number becomes 1, it is a happy number.
            }
        }

        return false;  // If a cycle is detected, the number is not happy.
    }
};
