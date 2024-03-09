class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        int nums1Counter = 0;
        int nums2Counter = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();

        while (nums1Counter < len1 && nums2Counter < len2)
            if (nums1[nums1Counter] < nums2[nums2Counter])
                nums1Counter++;
            else if (nums1[nums1Counter] > nums2[nums2Counter])
                nums2Counter++;
            else
                return nums1[nums1Counter];

        return -1;

    }
};