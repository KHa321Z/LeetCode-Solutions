class Solution {
public:
    bool help(vector<int>& arr, vector<bool>& freq, int n, int index = 0) {

        if (index == arr.size())
            return true;

        if (arr[index])
            return help(arr, freq, n, index + 1);

        for (int i = n; i > 0; i--) {
            if (!freq[i - 1]) {

                if ((i != 1) && ((index + i >= arr.size()) || arr[index + i]))
                    continue;

                freq[i - 1] = true;
                arr[index] = i;

                if (i != 1)
                    arr[index + i] = i;

                if (help(arr, freq, n, index + 1))
                    return true;

                if (i != 1)
                    arr[index + i] = 0;

                freq[i - 1] = false;
                arr[index] = 0;
                
            }
        }

        return false;

    }

    vector<int> constructDistancedSequence(int n) {
        
        vector<int> arr(2 * n - 1);
        vector<bool> freq(n);
        help(arr, freq, n);

        return arr;

    }
};