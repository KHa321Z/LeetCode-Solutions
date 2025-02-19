class Solution {
public:
    void recursion(vector<string>& unique, char *hapi, int n, string curr, int index = 1) {

        if (index == n) {
            unique.push_back(curr);
            return;
        }

        int ch = curr[curr.length() - 1] - 'a';
        recursion(unique, hapi, n, curr + hapi[(ch + 1) % 3], index + 1);
        recursion(unique, hapi, n, curr + hapi[(ch + 2) % 3], index + 1);

    }

    string getHappyString(int n, int k) {
        
        char hapi[] = {'a', 'b', 'c'};
        vector<string> unique;

        recursion(unique, hapi, n, "a");
        recursion(unique, hapi, n, "b");
        recursion(unique, hapi, n, "c");

        sort(unique.begin(), unique.end());
        return (k <= unique.size()) ? unique[k - 1] : "";

    }
};