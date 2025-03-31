class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        
        long long answer = 0;
        int n = weights.size();
        vector<int> pairW(n - 1);

        for (int i = 0; i < n - 1; i++)
            pairW[i] += weights[i] + weights[i + 1];

        sort(pairW.begin(), pairW.end());

        for (int i = 0; i < k - 1; i++)
            answer += pairW[n - 2 - i] - pairW[i];

        return answer;

    }
};