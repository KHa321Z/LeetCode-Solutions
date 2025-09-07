class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> arr(n);

        for (int i = 0; i < n / 2; i++)
            arr[2 * i] = i + 1, arr[2 * i + 1] = -(i + 1);

        return arr;
    }
};