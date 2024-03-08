class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {

        int length = nums.size();
        int maxFreq = 0;
        int freq = 0;
        int countArray[100] = {};

        for (int i = 0; i < length; i++) {
            countArray[nums[i] - 1]++;

            if (countArray[nums[i] - 1] > maxFreq)
                maxFreq = countArray[nums[i] - 1];
        }

        for (int i = 0; i < 100; i++)
            if (countArray[i] == maxFreq)
                freq += maxFreq;

        return freq;

    }
};