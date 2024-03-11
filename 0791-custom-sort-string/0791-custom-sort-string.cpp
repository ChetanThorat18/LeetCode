class Solution {
public:
    // Static vector (Because it is to be used in static myComparator ) to map indices of characters in the string 'order'
    static vector<int> indexMap;

    // Comparator function to compare characters based on their indices in the string 'order'
    static bool myComparator(char &ch1, char &ch2) {
        return indexMap[ch1 - 'a'] < indexMap[ch2 - 'a'];
    }

    string customSortString(string order, string s) {
        // Initialize the indexMap with -1 
        indexMap = vector<int>(26, -1);

        // Populate the indexMap with indices of characters in the string 'order'
        for (int i = 0; i < order.length(); i++) {
            char ch = order[i];
            indexMap[ch - 'a'] = i;
        }

        // Sort the string s based on the custom 'order' using the custom comparator function
        sort(s.begin(), s.end(), myComparator);

        return s;
    }
};

// Static member initialization 
vector<int> Solution::indexMap;

/*
    Time Complexity : O(nlogn)
    Space Complexity : O(1)
*/