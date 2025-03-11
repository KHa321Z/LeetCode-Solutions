class Solution {
public:
    int numberOfSubstrings(string s) {

        int count = 0;
        list<int> a, b, c;

        for (int i = 0; i < s.length(); i++)
            if (s[i] == 'a')
                a.push_back(i);
            else if (s[i] == 'b')
                b.push_back(i);
            else
                c.push_back(i);

        auto a_itr = a.begin(), b_itr = b.begin(), c_itr = c.begin();

        for (int i = 0; i < s.length(); i++) {

            while (*a_itr < i && a_itr != a.end())
                advance(a_itr, 1);

            while (*b_itr < i && b_itr != b.end())
                advance(b_itr, 1);
            
            while (*c_itr < i && c_itr != c.end())
                advance(c_itr, 1);

            if (a_itr == a.end() || b_itr == b.end() || c_itr == c.end())
                break;

            count += s.length() - max(*a_itr, max(*b_itr, *c_itr));

        }

        return count;

    }
};