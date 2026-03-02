class Solution {
public:
    int totalStrength(vector<int>& strength) {
        
        const long long MOD = 1e9 + 7;
        int n = strength.size();
        long long total = 0;

        stack<int> st;
        vector<int> left(n, -1), right(n, n), p(n + 1, 0), pp(n + 2, 0);

        for (int i = 0; i < n; i++) {
            while (st.size() && strength[st.top()] >= strength[i])
                right[st.top()] = i, st.pop();
            
            st.push(i);
        }

        st = stack<int>();

        for (int i = n - 1; i >= 0; i--) {
            while (st.size() && strength[st.top()] > strength[i])
                left[st.top()] = i, st.pop();

            st.push(i);
        }

        for (int i = 0; i < n; i++)
            p[i + 1] = (p[i] + strength[i]) % MOD;

        for (int i = 0; i <= n; i++)
            pp[i + 1] = (pp[i] + p[i]) % MOD;

        for (int i = 0; i < n; i++) {

            int l = left[i] + 1, r = right[i] - 1;
            int left_len = i - l + 1, right_len = r - i + 1;

            long long first = (pp[r + 2] - pp[i + 1] + MOD) % MOD;
            long long second = (pp[i + 1] - pp[l] + MOD) % MOD;
            long long sum = (left_len * first % MOD - right_len * second % MOD + MOD) % MOD;

            total = (total + strength[i] * sum % MOD) % MOD;

        }

        return total;

    }
};