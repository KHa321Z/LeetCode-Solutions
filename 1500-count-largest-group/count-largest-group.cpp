class Solution {
public:
    int countSum(int n) {

        int sum = 0;

        for (int digit = n % 10; n; n /= 10, digit = n % 10)
            sum += digit;

        return sum;

    }

    int countLargestGroup(int n) {
        
        int highest = 0;
        int count = 0;
        unordered_map<int, int> mep;

        for (int i = 1; i <= n; i++)
            highest = max(highest, ++mep[countSum(i)]);

        for (auto& [_, value] : mep)
            if (value == highest)
                count++;

        return count;

    }
};