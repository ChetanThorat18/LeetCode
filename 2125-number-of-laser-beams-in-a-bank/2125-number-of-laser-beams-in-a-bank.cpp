class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size(); 

        int numberOfBeams = 0; 
        int prevDeviceCount = 0; // Initialize the count of security devices in the previous row.

        for(int i = 0; i < n; i++) {

            int currDeviceCount = 0; // Initialize the count of security devices in the current row.
            
            // Iterate through each character in the current row.
            for(char &ch : bank[i]) {
                if(ch == '1')
                    currDeviceCount++; // Increment the count of security devices if the cell contains '1'.
            }

            // Update the total number of beams by multiplying the count of devices in the current row
            // with the count of devices in the previous row.
            numberOfBeams += (currDeviceCount * prevDeviceCount);

            // If the current row contains at least one security device,
            // update the count of devices in the previous row to the count of devices in the current row.
            // if current row contains zero security device , then count of devices in the previous row will remain same
            if(currDeviceCount != 0) {
                prevDeviceCount = currDeviceCount;
            }
        }

        return numberOfBeams; 
    }
};