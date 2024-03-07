class Solution {
public:

    int calculateEvenSum(vector<int>&nums){
        int sum = 0;
        for(int &num : nums){
            if( num % 2 == 0)
                sum += num;
        }

        return sum;
    }

    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        // Brute Force  O(N*n) 
        int n = nums.size();
        int N = queries.size();

        vector<int>answer;

        for(auto query : queries){
            int value = query[0];
            int index = query[1];

            nums[index] = nums[index] + value;

            int evenSum = calculateEvenSum(nums);

            answer.push_back(evenSum);
        }

        return answer;
    }
};
