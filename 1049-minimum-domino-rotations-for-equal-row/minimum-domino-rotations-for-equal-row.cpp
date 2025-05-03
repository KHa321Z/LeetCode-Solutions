class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {

        int n = tops.size();
        int top1 = 0, bottom1 = 0, top2 = 0, bottom2 = 0;
        bool only1 = false, only2 = false;
        int choice1 = tops[0], choice2 = bottoms[0];

        for (int i = 0; i < n; i++) {
            if (tops[i] != choice1 && tops[i] != choice2 && bottoms[i] != choice1 && bottoms[i] != choice2)
                return -1;

            if (tops[i] == choice1) top1++;
            if (tops[i] == choice2) top2++;
            if (bottoms[i] == choice1) bottom1++;
            if (bottoms[i] == choice2) bottom2++;
            if (tops[i] == bottoms[i])
                if (tops[i] == choice1) only1 = true;
                else only2 = true;
        }

        if (top1 + bottom1 >= n && top2 + bottom2 >= n && !only1 && !only2)
            return min(n - max(top1, bottom2), min(top1, bottom2));

        else if (!only2 && top1 + bottom1 >= n)
            return min(min(n - top1, top1), min(n - bottom1, bottom1));

        else if (!only1 && top2 + bottom2 >= n)
            return min(min(n - bottom2, bottom2), min(n - top2, top2));

        else
            return -1;
        
    }
};