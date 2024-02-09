class Solution {
public:
    string frequencySort(string s) {

        string sortedString = s;
        int frequencyArray[62] = {};

        for (char character: s)
            frequencyArray[character - ((character <= '9') ? '0' : ((character <= 'Z') ? 'A' - 10 : 'a' - 36))]++;

        sort(s.begin(), s.end(), [&](char a, char b) {
            return frequencyArray[a - ((a <= '9') ? '0' : ((a <= 'Z') ? 'A' - 10 : 'a' - 36))] > frequencyArray[b - ((b <= '9') ? '0' : ((b <= 'Z') ? 'A' - 10 : 'a' - 36))] || 
                (frequencyArray[a - ((a <= '9') ? '0' : ((a <= 'Z') ? 'A' - 10 : 'a' - 36))] == frequencyArray[b - ((b <= '9') ? '0' : ((b <= 'Z') ? 'A' - 10 : 'a' - 36))] && a < b);
        });

        return s;
        
    }
};