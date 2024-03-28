class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // boolean array to mark visited positive integers in range (1,n)
        vector<bool> visited(n + 1, false);

        // Mark the positive integers(1-n) in the boolean array as visited
        for (int &num : nums) {
            if (num > 0 && num <= n) {
                int idx = num;
                visited[idx] = true;
            }
        }

        // Iterate through the boolean array to find the first missing positive integer
        for (int i = 1; i <= n; i++) {
            if (visited[i] == false) {
                return i;  // Return the first missing positive integer
            }
        }

        // If no missing positive integer found, return the next positive integer after the array size
        return n + 1;
    }
};


/*
    Intuition : 

    We have to find smallest missing positive integer . 
    So , in a array of size of n , smallest positive integer can be in range 1 to n
    So ignore numbers less than zero and greater than n.
    If all numbers in range 1 to n are present , it means smallest missing posistive will be n+1

*/
