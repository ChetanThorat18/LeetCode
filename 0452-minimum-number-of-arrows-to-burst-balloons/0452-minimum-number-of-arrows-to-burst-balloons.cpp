class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size(); 

        // Sort the balloons based on their start points
        sort(points.begin(), points.end());

        // vector 'prev' to store the first balloon's coordinates
        vector<int> prev = points[0];

        int count = 1; // Initialize the count of arrows to 1 (assuming at least one arrow is needed for first balloon)

        
        for(int i = 1; i < n; i++) {
            // Get the start and end points of the current balloon
            int currStartPoint = points[i][0];
            int currEndPoint = points[i][1];

            // Get the start and end points of the previous balloon
            int prevStartPoint = prev[0];
            int prevEndPoint = prev[1];

            // If the current balloon starts after the end of the previous balloon
            // It means there is no overlap
            if(currStartPoint > prevEndPoint) {
                // Increment the count of arrows since a new arrow is needed to burst the current balloon
                count++;
                // assign current balloon as the new reference point for determining whether subsequent balloons 
                // can be burst by the same arrow , as (Prev will not get any further overlapping balloons)
                // So , Update the 'prev' vector to the current balloon's coordinates
                prev = points[i];

            // If balloons are overlapping 
            } else {
                // update the 'prev' vector to overlapping part
                // prev is updated to common area between the current and previous balloons, ensuring that subsequent balloons are correctly handled
                prev[0] = max(prevStartPoint, currStartPoint);
                prev[1] = min(prevEndPoint, currEndPoint);
            }
        }

        return count; 
    }
};
