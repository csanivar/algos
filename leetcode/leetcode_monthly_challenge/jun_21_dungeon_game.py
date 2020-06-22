class Solution:
        
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        n = len(dungeon)
        m = len(dungeon[0])
        MAX = pow(2,32)
        dp = [[0]*m]*n
        for x in range(n-1, -1, -1):
            for y in range(m-1, -1, -1):
                if x == n-1 and y == m-1:
                    dp[x][y] = 1 if dungeon[x][y] >= 0 else abs(dungeon[x][y])+1
                    continue
                if y+1 >= m:
                    right = MAX
                else:
                    right = max(1, dp[x][y+1] - dungeon[x][y])
                if x+1 >= n:
                    down = MAX
                else:
                    down = max(1, dp[x+1][y] - dungeon[x][y])
                dp[x][y] = min(right, down)
        
        return dp[0][0]
                
