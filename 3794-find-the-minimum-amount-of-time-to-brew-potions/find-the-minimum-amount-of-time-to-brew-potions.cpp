class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        
        vector<vector<long long>> tt(mana.size(), vector<long long>(skill.size() + 1));

        for (int i = 1; i < skill.size() + 1; i++)
            tt[0][i] = tt[0][i - 1] + skill[i - 1] * mana[0];

        for (int i = 1; i < mana.size(); i++) {

            tt[i][0] = tt[i - 1][1];

            for (int j = 1; j < skill.size() + 1; j++) {
                tt[i][j] = max(tt[i - 1][j], tt[i][j - 1]) + skill[j - 1] * mana[i];
            }

            for (int j = skill.size() - 1; j >= 0; j--) {
                tt[i][j] = tt[i][j + 1] - skill[j] * mana[i];
            }

        }

        return tt[mana.size() - 1][skill.size()];

    }
};