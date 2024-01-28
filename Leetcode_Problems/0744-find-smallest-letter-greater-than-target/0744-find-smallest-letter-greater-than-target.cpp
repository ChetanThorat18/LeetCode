class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // Approach : Binary Search

        int left = 0;
        int right = letters.size()-1;

        char result = letters[0];
        while(left <= right){
            int mid = left + (right - left)/2;

             // If middle element is greater than the target
            if( letters[mid] > target){
                // Update result and move right pointer to the left as we are interested in finding smallest greater than target
                result = letters[mid];
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        // Check if result is still the initial value
        // If it is, return result; otherwise, return letters[left]
        return result == letters[0] ? result : letters[left];
    }
};