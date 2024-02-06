class Solution {
public:
    // Function to count the number of set bits in the binary representation of a number
    int countSetBits(int num) {
        int count = 0;
        // Continue counting until all bits are processed
        while (num != 0) {
            // Check if the rightmost bit is set (equals 1)
            if ((num & 1) == 1) {
                count++;
            }
            // Right shift the bits by 1 position
            num >>= 1;
        }
        return count;
    }

    vector<int> countBits(int n) {
        vector<int> ans(n + 1);

        for (int i = 0; i <= n; i++) {
            ans[i] = countSetBits(i);
        }

        return ans;
    }
};
