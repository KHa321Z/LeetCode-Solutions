class Solution {
public:
    bool validate(long long num, long long target) { return num * num <= target; }

    int mySqrt(int x) {
        
        int l = 0, h = x, best = 0;

        while (l <= h) {
            int m = l + (h - l) / 2;

            if (validate(m, x))
                best = m, l = m + 1;
                
            else
                h = m - 1;
        }

        return best;

    }
};