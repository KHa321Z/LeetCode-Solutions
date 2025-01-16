class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {

        int num1 = 0;
        int num2 = 0;
        int s1 = nums1.size();
        int s2 = nums2.size();

        if (s1 % 2)
            for (int i = 0; i < s2; i++)
                num2 ^= nums2[i];

        if (s2 % 2)
            for (int i = 0; i < s1; i++)
                num1 ^= nums1[i];

        return num1 ^ num2;
        
    }
};