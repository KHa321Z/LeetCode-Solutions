class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {

        int freq[10] = {};
        vector<int> nums;

        for (int digit : digits)
            freq[digit]++;

        for (int i = 100; i < 1000; i++) {
            int first = (i / 100) % 10;
            int second = (i / 10) % 10;
            int third = i % 10;

            --freq[first];
            --freq[second];
            --freq[third];

            if (freq[first] >= 0 && freq[second] >= 0 && freq[third] >= 0 && i % 2 == 0)
                nums.push_back(i);

            freq[first]++;
            freq[second]++;
            freq[third]++;
        }

        return nums;
        
    }
};