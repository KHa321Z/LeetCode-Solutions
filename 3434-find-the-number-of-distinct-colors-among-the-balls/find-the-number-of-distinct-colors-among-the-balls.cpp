class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        
        unordered_map<int, int> bolls;
        unordered_map<int, int> cols;
        unordered_set<int> colors;
        vector<int> distinct(queries.size());

        for (int i = 0; i < queries.size(); i++) {

            if (bolls[queries[i][0]] && !(--cols[bolls[queries[i][0]]]))
                colors.erase(bolls[queries[i][0]]);

            cols[queries[i][1]]++;
            colors.insert(bolls[queries[i][0]] = queries[i][1]);
            distinct[i] = colors.size();

        }

        return distinct;

    }
};