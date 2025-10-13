class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = profit.size();
        map<int, int> dp;
        vector<tuple<int, int, int>> jobs;

        for (int i = 0; i < n; i++)
            jobs.push_back({ startTime[i], endTime[i], profit[i] });

        sort(jobs.begin(), jobs.end());

        dp.insert({ get<0>(jobs[n - 1]), get<2>(jobs[n - 1]) });

        for (int i = n - 2; i >= 0; i--) {

            auto [st, et, p] = jobs[i];
            auto last = dp.lower_bound(et);
            auto next = dp.lower_bound(st);

            if (last != dp.end())
                p += last->second;

            if (next != dp.end() && next->first == st)
                dp[st] = max(dp[st], p);
            
            else {
                if (next != dp.end())
                    p = max(p, next->second);

                dp.insert({ st, p });
            }

        }

        return dp.lower_bound(get<0>(jobs[0]))->second;

    }
};