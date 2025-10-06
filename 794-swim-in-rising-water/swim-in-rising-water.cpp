class Solution {
public:
    class DSU {

        vector<int> parent;
        vector<int> r;
        
        public:
        
            DSU(int n) : parent(n), r(n, 1) {
               
                for (int i = 0; i < n; i++)
                    this->parent[i] = i;
                
            }
            
            int find(int x) {
                return this->parent[x] == x ? x : (this->parent[x] = this->find(this->parent[x]));
            }
            
            bool unionSet(int x, int y) {
                
                int xFind = this->find(x);
                int yFind = this->find(y);
                
                if (xFind == yFind) return false;
                
                if (this->r[xFind] < this->r[yFind])
                    swap(xFind, yFind); 
                
                   
                this->r[xFind] += this->r[yFind];
                this->parent[yFind] = xFind;
                    
                return true;    
                
            }
            
            bool connected(int x, int y) {
                return this->find(x) == this->find(y);
            }

    };

    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        DSU dsu(n * n);
        unordered_map<int, pair<int, int>> mep;
        int directions[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                mep[grid[i][j]] = {i,j};
        
        for (int i = 0; i < n * n; i++) { 
            
            pair<int, int> index = mep[i]; 
            if (dsu.connected(grid[0][0], grid[n - 1][n - 1]))
                return i;
                
            for (auto& d : directions) {
                
                int nx = index.first + d[0], ny = index.second + d[1];
                
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] < i)
                    dsu.unionSet(i, grid[nx][ny]);
                
            } // oops
            
            if (dsu.connected(grid[0][0], grid[n - 1][n - 1]))
                return i;
            
        }
        
        return 0;
        
    }
};