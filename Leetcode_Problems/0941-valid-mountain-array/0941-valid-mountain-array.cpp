class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        /* Approach =>  Two people climb from left and from right separately.
         If they are climbing the same mountain,
         they will meet at the same point.  */ 

        int n = arr.size();
        if (n < 3) {
            return false;
        }

        int left = 0, right = n - 1;

        // Left Climbing
        while (left < n - 1 && arr[left] < arr[left + 1]) {
            left++;
        }

        // Right Climbing
        while (right > 0 && arr[right] < arr[right - 1]) {
            right--;
        }

        // Check Validity
        return left > 0 && right < n - 1 && left == right;
    }
};


/*
    If complete array is in decreasing order ,  left will remain at  0 
    If complete array is in increasing order right will be at n-1 , return false in these cases
*/
