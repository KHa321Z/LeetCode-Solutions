class Solution {
public:
    int fact(int x) { return (x == 0) ? 1 : x * fact(x - 1); }

    int permuteCount(string& tile) {
        
        int total = fact(tile.length());
        int charCount[26] = {};

        for (char ch : tile)
            charCount[ch - 'A']++;

        for (int freq : charCount)
            if (freq > 1)
                total /= fact(freq);

        return total;

    }

    int permutations(string& tiles, unordered_set<string>& perms, string current = "", int index = 0) {

        if (index >= tiles.length())
        return (perms.insert(current).second) ? permuteCount(current) : 0;

        return permutations(tiles, perms, current, index + 1) + permutations(tiles, perms, current + tiles[index], index + 1);

    }

    int numTilePossibilities(string tiles) {

        unordered_set<string> perms;
        sort(tiles.begin(), tiles.end());

        return permutations(tiles, perms) - 1;
        
    }
};