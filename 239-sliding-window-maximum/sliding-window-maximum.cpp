class Solution {
public:
    using pii = pair<int, int>;

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> res(n - k + 1);
        deque<pii> dq;

        int l = 0, r = 0;

        for (; r < k - 1; r++) {
            while (!dq.empty() && dq.back().first < nums[r])
                dq.pop_back();

            dq.push_back({nums[r], r});
        }

        for (; r < n; r++, l++) {
            while (!dq.empty() && dq.back().first < nums[r])
                dq.pop_back();

            dq.push_back({nums[r], r});

            res[l] = dq.front().first;

            if (dq.front().second == l)
                dq.pop_front();
        }

        return res;

    }
};