class Solution {
public:
    class State {
        public:
            int x;
            int y;
            int dis;

            State(int x, int y, int dis) : x(x), y(y), dis(dis) {}
    };

    int dirX[4] = { 0, 1, 0, -1 };
    int dirY[4] = { 1, 0, -1, 0 };

    bool validInd(int n, int m, int x, int y) { return (x >= 0 && x < n && y >= 0 && y < m); }

    int minTimeToReach(vector<vector<int>>& moveTime) {

        auto cmp = [](const State& a, const State& b) { return a.dis > b.dis; };
        
        int t = -1;
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> d(n, vector<int>(m, INT_MAX));
        vector<vector<int>> v(n, vector<int>(m, 0));
        priority_queue<State, vector<State>, decltype(cmp)> pq(cmp);

        d[0][0] = 0;
        pq.push(State(0, 0, 0));

        while (!pq.empty()) {

            State s = pq.top();
            pq.pop();

            if (v[s.x][s.y])
                continue;
            
            if ((s.x == n - 1) && (s.y == m - 1))
                break;
            
            v[s.x][s.y] = true;

            for (int dir = 0; dir < 4; dir++) {

                int nx = s.x + dirX[dir];
                int ny = s.y + dirY[dir];

                if (!validInd(n, m, nx, ny))
                    continue;

                int dist = max(d[s.x][s.y], moveTime[nx][ny]) + (s.x + s.y) % 2 + 1;

                if (d[nx][ny] > dist)
                    d[nx][ny] = dist, 
                    pq.push(State(nx, ny, dist));

            }

        }

        return d[n - 1][m - 1];

    }
};