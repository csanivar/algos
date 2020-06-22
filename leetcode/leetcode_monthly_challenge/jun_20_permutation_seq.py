class Solution:
    
    def factorial(self, n):
        ans = 1
        for i in range(1, n+1):
            ans *= i
        return ans
    
    def _getPermutation(self, arr, k):
        if len(arr) == 1:
            return arr
        if len(arr) == 2:
            if k == 1:
                return arr
            elif k == 2:
                arr.reverse()
                return arr
            elif k > 2:
                return [-1]
        fact = self.factorial(len(arr)-1)
        q = k // fact
        i = q-1 if k % fact == 0 else q
        done = i*fact
        return [arr[i]] + self._getPermutation(arr[0:i]+arr[i+1:], k - done)
    
    def getPermutation(self, n: int, k: int) -> str:
        arr = [i for i in range(1, n+1)]
        return "".join(str(x) for x in self._getPermutation(arr, k))
        
