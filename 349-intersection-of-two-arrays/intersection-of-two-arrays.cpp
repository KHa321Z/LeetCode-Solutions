class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        int len1 = nums1.size(), len2 = nums2.size();
        int freqArray[1001] = {};
        vector<int> result;

        for (int i = 0; i < len1; i++)
            if (!freqArray[nums1[i]])
                freqArray[nums1[i]]++;

        for (int j = 0; j < len2; j++)
            if (freqArray[nums2[j]])
                result.push_back(nums2[j]), freqArray[nums2[j]]--;

        return (result);
        
    }
};