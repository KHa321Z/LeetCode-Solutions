class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        /*
        x, y, z
        x + z >= a
        y + z >= b
        x, y, z >= 0
        min(cx + dy + ez)
        */

        return min({
            (long long)cost1 * need1 + (long long)cost2 * need2, 
            (long long)costBoth * max(need1, need2), 
            (long long)costBoth * min(need1, need2) + (long long)cost1 * (need1 - min(need1, need2)) + (long long)cost2 * (need2 - min(need1, need2))
        });

    }
};