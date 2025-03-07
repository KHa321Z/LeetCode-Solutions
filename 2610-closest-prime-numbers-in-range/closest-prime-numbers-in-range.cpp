class Solution {
public:
    bool isPrime(int n) {

        if (n <= 1)
            return false;

        for (int i = 2; i * i <= n; i++)
            if (n % i == 0)
                return false;

        return true;

    }

    vector<int> closestPrimes(int left, int right) {
        
        int ind = 0;
        int secondLast = 0;
        vector<int> primes(2, -1);

        for (; left <= right; left++)
            if (isPrime(left))
                if (ind > 1) {

                    if (left - primes[1] < primes[1] - primes[0])
                        primes[0] = primes[1], 
                        primes[1] = left;
                    
                    else if (left - secondLast < primes[1] - primes[0])
                        primes[0] = secondLast, 
                        primes[1] = left;

                    secondLast = left;

                } else
                    primes[ind++] = left;

        if (primes[1] == -1)
            primes[0] = -1;

        return primes;

    }
};