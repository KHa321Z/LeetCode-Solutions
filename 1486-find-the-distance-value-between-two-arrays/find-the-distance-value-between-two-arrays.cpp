class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        int cnt = 0;

        for (int i : arr1) {
            bool chk = true;
            for (int j : arr2)
                if (abs(i - j) <= d)
                    chk = false;
            if (chk) cnt++;
        }

        return cnt;

    }
};