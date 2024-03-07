class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();

        // If changed Array is a doubled array then it is guaranteed that it will of even size
        // For eg - Size[Original] => 3  then Size[Changed] => 3 + 3 = 6
        //  Size[Original] => 4  then Size[Changed] => 4 + 4 = 8
        if( n % 2 != 0){
            return {};
        }

        /*
            By sorting the array, we ensure that doubled values always appear after their
             corresponding original values, making it easier to check for them during iteration
        */
        sort(changed.begin(),changed.end());

        unordered_map<int,int>freq;

        for(int &num : changed){
            freq[num]++;
        }

        vector<int>result;

        for (int &num : changed) {
            int twice = num * 2;

            // If the frequency of the current element is 0, it has been used already
            if (freq[num] == 0) {
                continue;
            }

            // If the doubled value does not exist in the frequency map or its frequency is 0,
            // return an empty array as it violates the condition of a doubled array
            if (freq.find(twice) == freq.end() || freq[twice] == 0) {
                return {};
            }

            // Add the current element to the original array and decrement its frequency
            result.push_back(num);
            freq[num]--;

            // Decrement the frequency of the doubled value
            freq[twice]--;
        }


        return result;
    }
};