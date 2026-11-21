class Solution {
public:
    using pii = pair<int, int>;

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> res(n - k + 1);
        priority_queue<pii> pq;

        int l = 0, r = 0;

        for (; r < k - 1; r++)
            pq.push({nums[r], r});

        for (; r < n; r++) {
            pq.push({nums[r], r});

            while (pq.top().second < l)
                pq.pop();

            res[l++] = pq.top().first;
        }

        return res;

    }
};