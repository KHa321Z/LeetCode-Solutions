class Solution {
public:
    static int intersectionSizeTwo(vector<vector<int>>& a) {
        
        sort(a.begin(), a.end(), [](auto& x, auto& y) {
            if (x[1] != y[1]) 
                return x[1] < y[1];

            return x[0] > y[0];
        });

        int start = -1, end = -1, count = 0;

        for (auto& in : a)
            if (in[0] > end)
                start = in[1] - 1, 
                end = in[1], 
                count += 2;

            else if (in[0] > start)
                start = end, 
                end = in[1], 
                count += 1;

        return count;
    }
};