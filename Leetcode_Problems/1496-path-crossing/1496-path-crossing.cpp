class Solution {
public:
    bool isPathCrossing(string path) {
        // Set to store the visited co-ordinates
        unordered_set<string>set;

        int x=0, y=0;

        set.insert("0_0");

        for(char &ch : path){
            if(ch == 'E')
                x++; // ---->
            else if(ch == 'W')
                x--; // <----
            else if(ch == 'N')
                y++;
            else
                y--;

            // Check if current co-ordinates are already visited
            string key = to_string(x) + "_" + to_string(y);
            if(set.count(key) > 0)
                return true;

            set.insert(key);
        }

        return false;
    }
};