class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        
        int first = 0, sec = 0, ind = 0;
        vector<vector<int>> res(nums1.size() + nums2.size(), vector<int>(2));
        
        while (first < nums1.size() || sec < nums2.size())
            if ((first < nums1.size()) && (sec < nums2.size()) && (nums1[first][0] == nums2[sec][0]))
                res[ind][0] = nums1[first][0], 
                res[ind][1] = nums1[first++][1] + nums2[sec++][1], 
                ind++;

            else if (!(sec < nums2.size()) || ((first < nums1.size()) && (nums1[first][0] < nums2[sec][0])))
                res[ind][0] = nums1[first][0],
                res[ind][1] = nums1[first][1], 
                ind++, 
                first++;
            
            else 
                res[ind][0] = nums2[sec][0], 
                res[ind][1] = nums2[sec][1], 
                ind++, 
                sec++;

        res.resize(ind);

        return res;

    }
};