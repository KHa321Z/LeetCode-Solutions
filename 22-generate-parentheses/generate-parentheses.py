class Solution:
    def brute(self, bracks, n, l=0, r=0, s=""):
        if (r == n):
            bracks.append(s)

        if (l < n):
            self.brute(bracks, n, l + 1, r, s + "(")

        if (r < l):
            self.brute(bracks, n, l, r + 1, s + ")")

    def generateParenthesis(self, n: int) -> list[str]:
        b = []
        self.brute(b, n)
        return b