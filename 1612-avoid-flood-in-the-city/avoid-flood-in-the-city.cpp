class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {

        int n = rains.size();
        vector<int> ans(n, -1);
        set<int> free;
        unordered_map<int, int> lake;

        for (int i = 0; i < n; i++)
            if (rains[i] == 0)
                free.insert(i);

            else if (lake.count(rains[i]) == 0)
                lake[rains[i]] = i;
            
            else if (free.size()) {
                auto it = free.lower_bound(lake[rains[i]]);

                if (it == free.end())
                    return vector<int>();
                else
                    ans[*it] = rains[i], 
                    free.erase(it), 
                    lake[rains[i]] = i;
            }

            else
                return vector<int>();

        for (int idx : free)
            ans[idx] = 1;

        return ans;
    }
};