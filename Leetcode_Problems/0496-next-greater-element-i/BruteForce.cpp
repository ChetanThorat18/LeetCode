class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Brute Force
        vector<int>result(nums1.size());
/*
    For each element in nums1 , find same in nums2 and then find next greater element

*/
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    bool found = false;
                    for(int k=j+1; k<nums2.size(); k++){
                        if(nums2[k] > nums1[i]){
                            found = true;
                            result[i] = nums2[k];
                            break;
                        }
                    }

                    if(!found)
                    result[i] = -1;
                }
            }
        }

        return result;
    }
};
