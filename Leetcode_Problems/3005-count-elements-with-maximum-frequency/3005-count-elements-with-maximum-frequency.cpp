class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {

       //map to store the frequency of each element
       unordered_map<int,int> freq;
       int maxFreq = -1;

       for(int &num : nums){
           // Update the frequency count of each element
           freq[num]++;
           // Update the maximum frequency encountered
           maxFreq = max(maxFreq,freq[num]);
       }

       int count = 0;
       // Iterate through the frequency map
       for(auto &itr : freq){
           // If the frequency of the element is equal to maxFreq, add its frequency to the count
           if(itr.second == maxFreq){
               count += maxFreq;
           }
       } 

       return count;
    }
};
