class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // Brute Force
        vector<int> positive;
        vector<int> negative;

        // Separate positive and negative integers in two different arrays
        for (int num : nums) {
            if (num > 0)
                positive.push_back(num);
            else
                negative.push_back(num);
        }

        vector<int> result;

        // Interleave positive and negative integers
        int i = 0, j = 0;
        while (i < positive.size() && j < negative.size()) {
            result.push_back(positive[i++]);
            result.push_back(negative[j++]);
        }

        return result;
    }
};
