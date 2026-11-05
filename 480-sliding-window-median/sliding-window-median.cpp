class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();
        multiset<double> lo, hi;
        vector<double> meds(n - k + 1);

        for (int i = 0; i < k; i++)
            lo.insert(nums[i]);

        while (lo.size() > (k + 1) / 2)
            hi.insert(*lo.rbegin()), 
            lo.erase(prev(lo.end()));

        for (int l = 0, r = k; r <= n; r++, l++) {

            meds[l] = (k % 2) ? *lo.rbegin() : (*lo.rbegin() + *hi.begin()) / 2.0;

            if (r == n) break;

            if (nums[l] <= *lo.rbegin())
                lo.erase(lo.find(nums[l]));
            else
                hi.erase(hi.find(nums[l]));

            if (lo.size() && nums[r] <= *lo.rbegin()) 
                lo.insert(nums[r]);
            else
                hi.insert(nums[r]);

            while (lo.size() > hi.size() + 1)
                hi.insert(*lo.rbegin()),
                lo.erase(prev(lo.end()));
            
            while (lo.size() < hi.size())
                lo.insert(*hi.begin()),
                hi.erase(hi.begin());

        }

        return meds;

    }
};