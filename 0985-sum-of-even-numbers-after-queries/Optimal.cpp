class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
       
        int n = nums.size();
        int N = queries.size();

        // Calculate Initial sum of Even numbers in array
        int sumOfEven = 0;
        for(int &num : nums){
            if( num % 2 == 0)
                sumOfEven += num;
        }

        vector<int>answer;

        for(auto query : queries){
            int value = query[0];
            int index = query[1];

            // If the current number at the index is even, subtract it from the sum of even numbers
            if( nums[index] % 2 == 0 ){
                sumOfEven = sumOfEven - nums[index];
            }

            // Update the number at the given index
            nums[index] = nums[index] + value;

            // If the new number at the index is even, add it to the sum of even numbers
            if(nums[index] % 2 == 0){
                sumOfEven = sumOfEven + nums[index];
            }

            // Store the current sum of even numbers in the answer 
            answer.push_back(sumOfEven);
        }

        return answer;
    }
};
