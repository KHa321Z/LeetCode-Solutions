class Solution {
public:
    int smallestRepunitDivByK(int k) {

        vector<bool> mods(k);

        if (k == 2 || k == 5)
            return -1;

        for (int i = 1, m = 1; i <= k; i++, m = (m * 10 + 1) % k)
            if (m % k == 0)
                return i;
            else if (mods[m % k])
                return -1;
            else
                mods[m % k] = true;

        return -1;
        
    }
};