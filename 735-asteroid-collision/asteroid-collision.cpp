class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        vector<int> s;

        for (int i : asteroids)
            if (s.empty() || !(i < 0 && s.back() > 0))
                s.push_back(i);
            else {
                bool chk = true;
                while (!s.empty() && i < 0 && s.back() > 0)
                    if (abs(i) <= abs(s.back())) {
                        if (abs(i) == abs(s.back()))
                            s.pop_back();
                        chk = false;
                        break;
                    } else
                        s.pop_back();
                if (chk)
                    s.push_back(i);
            }

        /* {
            if (s.empty() || (s.back() ^ i) >= 0)
                s.push_back(i);
            else if (abs(s.back()) == abs(i))
                s.pop_back();
            else {
                bool brk = true;
                while (!s.empty() && (s.back() ^ i) < 0) 
                    if (abs(s.back()) == abs(i)) {
                        brk = false;
                        s.pop_back();
                        break;
                    }
                    else if (abs(s.back()) < abs(i))
                        s.pop_back();
                    else {
                        i = s.back();
                        s.pop_back();
                        break;
                    }
                if (brk)
                    s.push_back(i);
            }
        }*/

        return s;

    }
};