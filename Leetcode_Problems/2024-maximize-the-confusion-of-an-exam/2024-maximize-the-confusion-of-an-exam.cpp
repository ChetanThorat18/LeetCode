class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i = 0, n = answerKey.size(), ans = 0;
        int T = 0, F = 0;

        // Subarray with maximum 'F's
        for (int j = 0; j < n; j++) {
            if (answerKey[j] == 'T')
                T++;

            // Slide the window to maintain at most 'k' 'T's
            while (T > k) {
                if (answerKey[i] == 'T')
                    T--;
                i++;
            }

            // Update the maximum length of consecutive answers
            ans = max(ans, j - i + 1);
        }


        i = 0;
        T = 0;

        // Subarray with maximum 'T's
        for (int j = 0; j < n; j++) {
            if (answerKey[j] == 'F')
                F++;

            // Slide the window to maintain at most 'k' 'F's
            while (F > k) {
                if (answerKey[i] == 'F')
                    F--;
                i++;
            }

            // Update the maximum length of consecutive answers
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};
