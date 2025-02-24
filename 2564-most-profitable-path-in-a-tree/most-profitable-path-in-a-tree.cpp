class Solution {
private:
    unordered_map<int, int> bobPath;
    vector<bool> visited;
    vector<vector<int>> tree;

    bool findBob(int source, int time) {

        bobPath[source] = time;
        visited[source] = true;

        if (!source)
            return true;

        for (int adjNode : tree[source])
            if (!visited[adjNode] && findBob(adjNode, time + 1))
                return true;

        bobPath.erase(source);
        return false;

    }

public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        
        int n = amount.size();
        int maxIncome = INT_MIN;

        tree.resize(n);
        visited.assign(n, false);
        queue<vector<int>> que;
        que.push({ 0, 0, 0 });

        for (vector<int> edge : edges)
            tree[edge[0]].push_back(edge[1]), 
            tree[edge[1]].push_back(edge[0]);

        findBob(bob, 0);
        visited.assign(n, false);

        while (!que.empty()) {

            int node = que.front()[0];
            int time = que.front()[1];
            int income = que.front()[2];

            if (bobPath.find(node) == bobPath.end() || time < bobPath[node])
                income += amount[node];

            else if (time == bobPath[node])
                income += (amount[node] / 2);

            if ((tree[node].size() == 1) && (node != 0))
                maxIncome = max(maxIncome, income);

            for (int adjNode : tree[node])
                if (!visited[adjNode])
                    que.push({ adjNode, time + 1, income });

            visited[node] = true;
            que.pop();

        }

        return maxIncome;

    }
};