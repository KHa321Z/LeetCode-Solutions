class Solution:
    def hasValidPath(self, grid: list[list[str]]) -> bool:
        n, m = len(grid), len(grid[0])
        dp = set()

        if ((n + m - 1) % 2 == 1 or grid[0][0] == ')' or grid[n - 1][m - 1] != ')'):
            return False

        def brute(i, j, b):
            if (i >= n or j >= m):
                return False

            b += 1 if grid[i][j] == '(' else -1

            if (i == n - 1 and j == m - 1):
                return b == 0
            elif (b < 0 or (i, j, b) in dp):
                return False

            dp.add((i, j, b))
            
            return brute(i + 1, j, b) or brute(i, j + 1, b)

        return brute(0, 0, 0)