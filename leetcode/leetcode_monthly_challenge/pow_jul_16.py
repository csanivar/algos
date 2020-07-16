class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n < 0:
            n = -n
            x = 1/x
        ans = 1
        cur = x
        i = n
        while i > 0:
            if i%2 == 1:
                ans = ans * cur
            cur = cur * cur
            i = i//2
        return ans
        
        
