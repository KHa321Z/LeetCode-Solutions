class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        
        int l = 0, r = 0, cur = 0;
        unordered_map<int, int> mp;
        vector<int> res(queries.size());
        vector<pair<int, int>> que(queries.size());

        for (int i = 0; i < queries.size(); i++)
            que[i] = {queries[i], i};

        sort(que.begin(), que.end());
        sort(logs.begin(), logs.end(), [](auto& logA, auto& logB) {
            return logA[1] < logB[1];
        });

        for (auto [t, idx] : que) {
            
            while (r < logs.size() && logs[r][1] <= t)
                if (mp[logs[r++][0]]++ == 0)
                    cur++;

            while (l < logs.size() && logs[l][1] < t - x)
                if (--mp[logs[l++][0]] == 0)
                    cur--;

            res[idx] = n - cur;

        }

        return res;

    }
};