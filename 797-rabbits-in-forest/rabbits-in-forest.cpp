class Solution {
public:
    int numRabbits(vector<int>& answers) {
        
        int total = 0;
        unordered_map<int, int> mep;

        for (int i : answers)
            mep[i]++;

        for (auto& p : mep)
            total += ceil((double)p.second / (p.first + 1)) * (p.first + 1);

        return total;

    }
};