class Solution {
public:
    string pushDominoes(string dominoes) {
        
        int force = 0;
        int n = dominoes.length();
        vector<int> forces(n);

        for (int i = 0; i < n; forces[i++] += force)
            if (dominoes[i] == 'R')
                force = n;
            else if (dominoes[i] == 'L')
                force = 0;
            else
                force = max(force - 1, 0);

        force = 0;

        for (int i = n - 1; i >= 0; forces[i--] -= force)
            if (dominoes[i] == 'L')
                force = n;
            else if (dominoes[i] == 'R')
                force = 0;
            else
                force = max(force - 1, 0);

        string ans = "";

        for (int f : forces)
            ans += (f > 0) ? 'R' : ((f < 0) ? 'L' : '.');

        return ans;

    }
};