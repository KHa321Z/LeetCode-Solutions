class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        
        int ans = 0;
        int forb = 0;

        for (int i = 20; i >= 0; i--) {

            int test = forb | (1 << i);
            bool possible = true;

            for (auto& row : grid) {
                bool found = false;

                for (int num : row)
                    if ((num & test) == 0) {
                        found = true;
                        break;
                    }

                if (!found) {
                    possible = false;
                    break;
                }
            }

            if (possible)
                forb = test;
            else
                ans |= (1 << i);

        }

        return ans;

    }
};