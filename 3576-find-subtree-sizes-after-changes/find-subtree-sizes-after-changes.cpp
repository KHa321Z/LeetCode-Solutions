class Solution {
public:
    void dfs(vector<vector<int>>& g, vector<int>& sub, int idx[], vector<int>& parent, const string& s, int node) {

        int prev = idx[s[node] - 'a'];
        idx[s[node] - 'a'] = node;

        if (prev != -1)
            parent[node] = prev;

        for (int v : g[node]) {
            // call dfs first and then add sub[parent] += 1 + sub[child]
            dfs(g, sub, idx, parent, s, v);

            if (parent[v] != -1)
                sub[parent[v]] += sub[v];
        }

        idx[s[node] - 'a'] = prev;

    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        
        int n = parent.size();
        int idx[26];
        vector<int> sub(n, 1);
        vector<vector<int>> g(n, vector<int>());

        for (int i = 1; i < n; i++)
            g[parent[i]].push_back(i);

        fill(idx, idx + 26, -1);
        dfs(g, sub, idx, parent, s, 0);

        return sub;

    }
};