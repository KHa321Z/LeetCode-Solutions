class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {

        int freq[101] = {};
        int rankMin = ranks[0], rankMax = ranks[0];

        for (int i = 0; i < ranks.size(); i++)
            freq[ranks[i]]++, 
            rankMin = min(rankMin, ranks[i]), 
            rankMax = max(rankMax, ranks[i]);

        long long low = 1, high = 1LL * rankMin * cars * cars;

        while (low < high) {

            long long currCars = 0;
            long long mid = (low + high) / 2;

            for (int i = 1; i <= rankMax; i++)
                currCars += freq[i] * (long long)floor(sqrt(mid / (long long)i));

            if (currCars < cars)
                low = mid + 1;
            else
                high = mid;
        }
        
        return low;

    }
};