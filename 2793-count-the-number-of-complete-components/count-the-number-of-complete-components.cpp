class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        int completeComps = 0;
        vector<bool> visited(n);
        vector<vector<int>> adjList(n);

        for (auto& edge : edges)
            adjList[edge[0]].push_back(edge[1]), 
            adjList[edge[1]].push_back(edge[0]);

        for (int i = 0; i < n; i++) {

            if (visited[i])
                continue;

            vector<int> connected;
            unordered_set<int> comps;

            visited[i] = true;
            connected.push_back(i);
            comps.insert(i);

            for (int i = 0; i < connected.size(); i++)
                for (int edge : adjList[connected[i]])
                    if (!visited[edge])
                        connected.push_back(edge), 
                        comps.insert(edge), 
                        visited[edge] = true;

            int connections = 0;
            int numOfComps = 0;

            for (int i = 0; i < connected.size(); i++) {
                for (int j = 0; j < adjList[connected[i]].size(); j++)
                    if (comps.find(adjList[connected[i]][j]) != comps.end())
                        numOfComps++;

                if (numOfComps != connected.size() - 1)
                    break;

                numOfComps = 0;
                connections++;
            }

            if (connections == connected.size())
                completeComps++;

        }

        return completeComps;
        
    }
};