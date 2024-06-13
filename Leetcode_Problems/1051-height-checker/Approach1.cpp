class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>expected(heights.begin() , heights.end());
        sort(expected.begin(),expected.end());

        int result = 0;
        for(int i=0; i<heights.size(); i++){
            result += (heights[i] != expected[i]);
        }

        return result;
    }
};
