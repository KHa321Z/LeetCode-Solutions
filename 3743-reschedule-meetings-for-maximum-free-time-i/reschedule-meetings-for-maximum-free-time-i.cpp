class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        
        int n = startTime.size();
        int maxFree = 0, free = 0;
        vector<int> freeTime(n + 1);

        for (int i = 0; i < n - 1; i++)
            freeTime[i + 1] = startTime[i + 1] - endTime[i];

        freeTime[0] = startTime[0];
        freeTime[n] = eventTime - endTime[n - 1];

        for (int i = 0, j = 0; i < n - k + 1; i++) {

            for (; (j - i) <= k; j++)
                free += freeTime[j];

            maxFree = max(maxFree, free);
            free -= freeTime[i];

        }

        return maxFree;

    }
};