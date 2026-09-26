class Solution:
    def evaluate(self, s: str, knowledge: list[list[str]]) -> str:
        knows = {i[0]: i[1] for i in knowledge}
        last = 0
        n = ""

        for i in range(len(s)):
            if (s[i] == '('):
                n += s[last:i]
                last = i + 1
            elif (s[i] == ')'):
                n += knows.get(s[last:i], '?')
                last = i + 1

        if (last != len(s)):
            n += s[last:]
        
        return n