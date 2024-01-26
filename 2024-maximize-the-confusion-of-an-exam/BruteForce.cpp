class Solution {
public:
    int result = 0;
    int n;

    // Helper function to find the maximum consecutive 'T's or 'F's
    void findMax(string &answerKey) {
        int length = 0;
        int i = 0;

        while (i < n) {
            if (answerKey[i] == 'T') {
                length = 1;
                i++;
                while (i < n && answerKey[i] == 'T') {
                    length++;
                    i++;
                }
                result = max(result, length);
            } else {
                length = 1;
                i++;
                while (i < n && answerKey[i] == 'F') {
                    length++;
                    i++;
                }
                result = max(result, length);
            }
        }
    }

    // Recursive function to explore all possible combinations
    void solve(int ind, string &answerKey, int k) {
        // Find the maximum consecutive 'T's or 'F's before making changes
        findMax(answerKey);

        if (ind >= n || k <= 0) {
            return;
        }

        // Toggle the current character
        answerKey[ind] = (answerKey[ind] == 'T') ? 'F' : 'T';
        solve(ind + 1, answerKey, k - 1);

        // Toggle it back
        answerKey[ind] = (answerKey[ind] == 'T') ? 'F' : 'T';
        solve(ind + 1, answerKey, k);
    }

    // Main function 
    int maxConsecutiveAnswers(string answerKey, int k) {
        n = answerKey.size();
        solve(0, answerKey, k);

        return result;
    }
};
