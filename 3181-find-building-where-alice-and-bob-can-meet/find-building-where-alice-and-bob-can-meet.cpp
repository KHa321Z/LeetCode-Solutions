class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        
        // q[0] >= q[1]. now we can sort on basis of q[0] on descending
        int qs = queries.size();
        int idx = (int)heights.size() - 1;
        vector<int> ans(qs, -1);
        vector<pair<int, int>> s;
        vector<vector<int>> que(qs);

        for (int i = 0; i < qs; i++)
            if (queries[i][0] < queries[i][1])
                que[i] = { queries[i][1], queries[i][0], i };
            else
                que[i] = { queries[i][0], queries[i][1], i };

        sort(que.rbegin(), que.rend());

        for (auto& q : que) {

            if (q[0] == q[1] || heights[q[1]] < heights[q[0]]) {
                ans[q[2]] = q[0];
                continue;
            }

            for (; idx >= 0 && idx >= q[0]; idx--) {
                while (s.size() && s.back().first <= heights[idx])
                    s.pop_back();

                s.push_back({ heights[idx], idx });
            }

            auto it = lower_bound(s.rbegin(), s.rend(), max(heights[q[0]], heights[q[1]]) + 1, [](const pair<int, int>& el, int val) { return el.first < val; });

            if (it != s.rend())
                ans[q[2]] =  (*it).second;

        }

        return ans;

    }
};