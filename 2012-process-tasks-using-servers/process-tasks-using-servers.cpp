class Solution {
public:
    using pll = pair<long long, long long>;
    using minheap = priority_queue<pll, vector<pll>, greater<pll>>;

    vector<int> assignTasks(vector<int>& s, vector<int>& t) {

        long long ts = 0;
        int m = s.size(), n = t.size();
        vector<int> ans;
        minheap busy, idle;

        for (int i = 0; i < m; i++)
            idle.emplace(s[i], i);

        auto free = [&]() {
            while (!busy.empty() && busy.top().first <= ts) {
                auto&& [_, idx] = busy.top();
                idle.emplace(s[idx], idx);
                busy.pop();
            }
        };

        for (int i = 0; i < n; i++) {
            ts = max(ts, (long long)i);
            free();

            if (idle.empty()) {
                ts = busy.top().first;
                free();
            }

            auto&& [_, idx] = idle.top();
            ans.push_back(idx);
            busy.emplace(ts + t[i], idx);
            idle.pop();
        }

        return ans;
        
    }
};