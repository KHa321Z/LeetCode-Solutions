class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {

        int cnt = 0;

        for (auto ops : operations)
            cnt += (ops[1] == '+') ? 1 : -1;

        return cnt;
        
    }
};