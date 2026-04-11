class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int cnt = 0;

        for (int i : nums)
            do {
                if (i % 10 == digit) cnt++;
                i /= 10;
            } while (i);

        return cnt;
    }
};