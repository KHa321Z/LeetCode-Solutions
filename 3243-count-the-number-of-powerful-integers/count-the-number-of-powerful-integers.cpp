class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return calculate(to_string(finish), s, limit) - calculate(to_string(start - 1), s, limit);
    }

    long long calculate(string x, string s, int limit) {

        if (x.length() < s.length())
            return 0;

        else if (x.length() == s.length())
            return (x >= s) ? 1 : 0;

        long long count = 0;
        int preLen = x.length() - s.length();
        string suffix = x.substr(preLen, s.length());

        for (int i = 0; i < preLen; i++) {
            if (limit < (x[i] - '0'))
                return (count += (long)pow(limit + 1, preLen - i));

            count += (long)(x[i] - '0') * (long)pow(limit + 1, preLen - 1 - i);
        }

        if (suffix >= s)
            count++;

        return count;

    }
};