class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        ans = [1]*(rowIndex+1)
        for i in range(rowIndex+1):
            for j in range(i-1, 0, -1):
                ans[j] = ans[j] + ans[j-1]
            
        return ans
                
# 2 [1, 2, 1, x] 
# 3 [1, 3, 3, 1, 1]
# 4 [1, 3, 6, 4, 1]
