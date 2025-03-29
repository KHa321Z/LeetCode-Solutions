class Solution {
private:
    const int MOD = 1e9 + 7;

    vector<int> getPrimes(int limit) {

        vector<bool> isPrime(limit + 1, true);
        vector<int> primes;

        for (int number = 2; number <= limit; number++) {
            if (!isPrime[number])
                continue;

            primes.push_back(number);

            for (long long multiple = (long long)number * number; multiple <= limit; multiple += number)
                isPrime[multiple] = false;
        }

        return primes;

    }

    long long power(long long base, long long exponent) {
        long long res = 1;

        // Calculate the exponentiation using binary exponentiation
        while (exponent > 0) {
            // If the exponent is odd, multiply the result by the base
            if (exponent % 2 == 1) {
                res = ((res * base) % MOD);
            }

            // Square the base and halve the exponent
            base = (base * base) % MOD;
            exponent /= 2;
        }

        return res;
    }

public:
    int maximumScore(vector<int>& nums, int k) {

        int n = nums.size();
        int maxElement = 0;
        vector<int> scores(n, 0);

        for (int i = 0; i < n; i++)
            maxElement = max(maxElement, nums[i]);
        
        vector<int> primes = getPrimes(maxElement);

        for (int i = 0; i < n; i++) {
            int num = nums[i];

            for (int prime : primes) {
                if (prime * prime > num)
                    break;
                else if (num % prime != 0)
                    continue;

                scores[i]++;

                while (num % prime == 0)
                    num /= prime;
            }

            if (num > 1)
                scores[i]++;
        }

        stack<int> stek;
        vector<int> nextDominant(n, n);
        vector<int> prevDominant(n, -1);

        for (int i = 0; i < n; i++) {
            while (!stek.empty() && scores[stek.top()] < scores[i])
                nextDominant[stek.top()] = i, 
                stek.pop();

            if (!stek.empty())
                prevDominant[i] = stek.top();

            stek.push(i);
        }

        long long score = 1;
        vector<long long> numSub(n);
        vector<pair<int, int>> keys(n);

        for (int i = 0; i < n; i++)
            numSub[i] = (long long)(nextDominant[i] - i) * (i - prevDominant[i]);

        for (int i = 0; i < n; i++)
            keys[i] = { nums[i], i };

        sort(keys.begin(), keys.end(), greater<>());

        for (int i = 0; k > 0;) {
            auto [num, index] = keys[i++];
            long long operations = min((long long)k, numSub[index]);
            score = (score * power(num, operations)) % MOD;
            k -= operations;
        }

        return score;

    }
};