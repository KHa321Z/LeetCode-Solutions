class Solution {
public:
    vector<int> primes;

    void sieve(int n) {
        vector<bool> nums(n + 1);

        for (long long i = 2; i <= n; i++)
            if (!nums[i]) {
                primes.push_back(i);
                
                for (long long j = i * i; j <= n; j += i)
                    nums[j] = true;
            }
    }

    int minOperations(vector<int>& nums) {
        
        int cnt = 0;
        sieve(100003);

        for (int i = 0; i < nums.size(); i++) {
            auto val1 = lower_bound(primes.begin(), primes.end(), nums[i]);
            auto val2 = upper_bound(primes.begin(), primes.end(), nums[i]);

            if (i % 2 && val1 != val2)
                cnt += 1 + (nums[i] == 2);
            else if (i % 2 == 0 && val1 == val2)
                cnt += *val2 - nums[i];
        }

        return cnt;

    }
};