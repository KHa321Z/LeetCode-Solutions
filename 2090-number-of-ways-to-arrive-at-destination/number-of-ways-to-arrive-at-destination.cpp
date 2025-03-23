class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        const int MOD = 1e9 + 7;
        vector<int> pathCount(n, 0);
        vector<long long> shortestTime(n, LLONG_MAX);
        vector<vector<pair<int, int>>> adjList(n);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> heap;

        shortestTime[0] = 0;
        pathCount[0] = 1;
        heap.emplace(0, 0);

        for (auto& road : roads)
            adjList[road[0]].emplace_back(road[1], road[2]), 
            adjList[road[1]].emplace_back(road[0], road[2]);

        while (!heap.empty()) {

            int currNode = heap.top().second;
            long long currTime = heap.top().first;
            heap.pop();

            if (currTime > shortestTime[currNode])
                continue;

            for (auto& [neighbor, roadTime] : adjList[currNode])
                if (currTime + roadTime < shortestTime[neighbor])
                    shortestTime[neighbor] = currTime + roadTime, 
                    pathCount[neighbor] = pathCount[currNode],
                    heap.emplace(shortestTime[neighbor], neighbor);

                else if (currTime + roadTime == shortestTime[neighbor])
                    pathCount[neighbor] = (pathCount[neighbor] + pathCount[currNode]) % MOD;

        }

        return pathCount[n - 1];

    }
};