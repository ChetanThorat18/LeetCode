class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // Approach : Binary Search

/*
    The relation between arr[index] and index helps to find the number of missing elements.
        For example, givenArray = [2,3,4,7,11].
        If there were no missing numbers, the actual array would have been ActualArray = [1,2,3,4,5].

        Now, let's find the number of missing elements at index 3 in givenArray:
        givenArray[3] = 7, but ideally, it should have been givenArray[3] = 4, 
        since ActualArray[3] = 4.
        So, the number of missing elements at index 3 in givenArray => (7 - 4) = 3.

        We don't need to maintain ActualArray; we can find the expected element at that index => index + 1.
        For example, at index 0, the expected is 1 (index + 1 => 0 + 1 = 1). Similarly, at index 3, the expected is 4.

*/ 

        int low=0, high = arr.size()-1;

        while(low <= high){
            int mid = low + (high-low)/2;
            // Find no. of missing elements at index , mid
            int missingCount = arr[mid] - (mid+1);

            // If the number of missing elements is less than k, search in the right half
            if(missingCount < k){
                low = mid+1;
            }
            // If the number of missing elements is greater than or equal to k, search in the left half
            else{
                high = mid - 1;
            }
        }

/*
     Given array arr = [2,3,4,7,11] and k = 5,
   After executing the logic in the provided code, 'low' will be at index 4, and 'high' will be at index 3.
   So, arr[high] = 7. Up to this point, 3 elements are missing.

   Therefore, ans = arr[high] + how-Many-More,
   where how-Many-More = k - (number of missings at high)
   In this case, how-Many-More = 5 - 3 = 2.

   So, ans = 7 + 2 = 9.

   Let's derive a formula:
   ans = arr[high] + how-Many-More,
   substitute how-Many-More, i.e., k - (number of missings at high)
   ans = arr[high] + k - (arr[high] - (high + 1)) 
   ans = arr[high] + k - arr[high] + high + 1
   ans = (high + 1) + k
   but, (high + 1) = low

   Therefore, ans = low + k.
*/

        return low + k;
    }
};