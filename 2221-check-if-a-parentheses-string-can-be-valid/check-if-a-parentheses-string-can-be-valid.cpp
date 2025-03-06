class Solution {
public:
    bool canBeValid(string s, string locked) {

        if (s.length() % 2)
            return false;

        stack<int> change, bracks;

        for (int i = 0; i < s.length(); i++)
            if (locked[i] == '0')
                change.push(i);
            else
                if (s[i] == ')')
                    if (change.empty() && bracks.empty())
                        return false;
                    else 
                        (bracks.empty() ? change : bracks).pop();

                else 
                    bracks.push(i);

        while (!change.empty() && !bracks.empty() && (bracks.top() < change.top()))
            change.pop(), bracks.pop();
                    
        return bracks.empty();

    }
};