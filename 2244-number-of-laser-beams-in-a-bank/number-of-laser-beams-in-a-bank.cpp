class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int cnt = 0;
        int l1 = 0, l2 = 0;

        for (int i = 0; i < bank.size(); i++) {
            
            for (char ch : bank[i])
                if (ch == '1')
                    l2++;

            if (l2 != 0)
                cnt += l1 * l2, 
                l1 = l2, 
                l2 = 0;

        }

        return cnt;

    }
};