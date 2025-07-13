class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        
        int cnt = 0;
        priority_queue<int> p, t;

        for (int i : players)
            p.push(i);

        for (int i : trainers)
            t.push(i);

        while (!p.empty() && !t.empty())
            if (p.top() <= t.top()) {
                p.pop();
                t.pop();
                cnt++;
            } else
                p.pop();

        return cnt;

    }
};