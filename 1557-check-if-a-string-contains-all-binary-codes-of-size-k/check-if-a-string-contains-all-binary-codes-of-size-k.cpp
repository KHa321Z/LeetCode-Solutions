class Solution {
public:
    bool hasAllCodes(string s, int k) {

        unordered_set<string> se;

        for (int i = 0; i + k - 1 < s.length(); i++) 
            se.insert(s.substr(i, k));
        
        return (se.size() == pow(2, k));

    }
};