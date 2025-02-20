class Solution {
public:
    void recursion(vector<string>& unique, int n, string curr, int index = 1) {

        if (index == n) {
            unique.push_back(curr);
            return;
        }

        for (char ch = 'a'; ch <= 'c'; ch++)
            if (curr[curr.length() - 1] != ch)
                recursion(unique, n, curr + ch, index + 1);

    }

    string getHappyString(int n, int k) {
        
        vector<string> unique;

        recursion(unique, n, "a");
        recursion(unique, n, "b");
        recursion(unique, n, "c");

        return (k <= unique.size()) ? unique[k - 1] : "";

    }
};