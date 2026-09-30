class Solution:
    def maxDepthAfterSplit(self, seq: str) -> list[int]:
        ans = [0 for i in range(len(seq))]
        dep = 0

        for i in range(len(seq)):
            if (seq[i] == '('):
                dep += 1
                ans[i] = dep % 2
            elif (seq[i] == ')'):
                ans[i] = dep % 2
                dep -= 1

        return ans
        