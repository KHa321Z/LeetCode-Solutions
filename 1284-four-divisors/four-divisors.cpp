class Solution {
public:
    unordered_set<int> sieve(int n) {

        unordered_set<int> s;
        vector<bool> primes(n + 1, true);
        primes[0] = primes[1] = false;

        for (int p = 2; p * p <= n; p++)
            if (primes[p])
                for (int i = p * p; i <= n; i += p)
                    primes[i] = false;

        for (int p = 2; p <= n; p++)
            if (primes[p])
                s.insert(p);

        return s;

    }

    int sumFourDivisors(vector<int>& nums) {

        int res = 0;
        unordered_set<int> s = sieve(*max_element(nums.begin(), nums.end()));

        for (int num : nums) {
            
            int p = round(cbrt(num));

            if (s.count(p) && p * p * p == num)
                res += (1 + p + p * p + num);

            else
                for (int x : s)
                    if ((num % x == 0) && (num / x != x) && s.count(x) && s.count(num/x)) {
                        res += (1 + x + num / x + num);
                        break;
                    }

        }

        return res;
        
    }
};