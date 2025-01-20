class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        vector<int> freqArray(mat.size() * mat[0].size());
        vector<pair<int, int>> paintedLines(freqArray.size());

        for (int i = 0; i < mat.size(); i++)
            for (int j = 0; j < mat[i].size(); j++)
                freqArray[mat[i][j] - 1] = i * mat[i].size() + j;

        for (int i = 0; i < arr.size(); i++)
            if ((++paintedLines[freqArray[arr[i] - 1] / mat[0].size()].first == mat[0].size()) || (++paintedLines[freqArray[arr[i] - 1] % mat[0].size()].second == mat.size()))
                return i;
        
        return 0;

    }
};