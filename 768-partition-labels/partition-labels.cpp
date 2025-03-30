class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> res;
        int lastInd[26] = {};

        for (int i = 0; i < s.length(); i++)
            lastInd[s[i] - 'a'] = i;

        for (int i = 0, start = 0, ind = -1; i < s.length(); i++) {

            ind = max(ind, lastInd[s[i] - 'a']);

            // check condition to be added
            if (i == ind) {
                res.push_back(ind - start + 1);
                start = ind + 1;
                ind = -1;

                continue;
            }

        }

        return res;

    }
};