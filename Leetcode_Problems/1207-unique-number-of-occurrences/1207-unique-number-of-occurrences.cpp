class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Initialize an array to store frequencies of numbers (ranging from -1000 to 1000 as per constraint)
        vector<int>freq(2001,0);
        // Count occurrences of each number and store in the frequency array
        for(int &num: arr){
            freq[num + 1000]++;  // Shifting by 1000 to make negative indices non-negative
        }

        sort(freq.begin(),freq.end());

        // Check if there are any duplicate counts in the sorted frequency array
        for(int i=1;i<2001;i++){
            if(freq[i] !=0 && freq[i] == freq[i-1])
                return false;
        }

        return true;
    }

    /* Advantage : Constant space complexity*/
};