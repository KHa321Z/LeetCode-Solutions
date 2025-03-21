class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {

        vector<string> creations;
        unordered_set<string> availableSupplies;
        unordered_map<string, int> recipeToIndex;
        unordered_map<string, vector<string>> depGraph;

        for (auto& supply : supplies)
            availableSupplies.insert(supply);

        for (int i = 0; i < recipes.size(); i++)
            recipeToIndex[recipes[i]] = i;

        vector<int> inDegree(recipes.size());

        for (int i = 0; i < recipes.size(); i++)
            for (string ingredient : ingredients[i])
                if (!availableSupplies.count(ingredient))
                    depGraph[ingredient].push_back(recipes[i]), 
                    inDegree[i]++;

            queue<int> q;

            for (int i = 0; i < recipes.size(); i++)
                if (!inDegree[i])
                    q.push(i);

            while (!q.empty()) {

                int recipeInd = q.front();
                string recipe = recipes[recipeInd];

                creations.push_back(recipe);
                q.pop();

                if (!depGraph.count(recipe))
                    continue;

                for (string& dependency : depGraph[recipe])
                    if (!(--inDegree[recipeToIndex[dependency]]))
                        q.push(recipeToIndex[dependency]);

            }

        return creations;
        
    }
};