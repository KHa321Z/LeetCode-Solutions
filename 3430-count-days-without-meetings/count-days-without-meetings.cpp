class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {

        vector<vector<int>> newMeets;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> meets;

        for (int i = 0; i < meetings.size(); i++)
            meets.push(meetings[i]);

        while (!meets.empty()) {

            vector<int> top = meets.top();
            meets.pop();

            while (!meets.empty() && (top[1] >= meets.top()[0]))
                top[1] = max(top[1], meets.top()[1]), 
                meets.pop();

            newMeets.push_back(top);

        }

        int free = newMeets[0][0] - 1 + days - newMeets[newMeets.size() - 1][1];

        for (int i = 0; i < newMeets.size() - 1; i++)
            free += newMeets[i + 1][0] - newMeets[i][1] - 1;

        return free;
        
    }
};